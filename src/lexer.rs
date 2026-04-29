use crate::token::{ Token, TokenType };
use crate::errors::ExalgoError;

pub struct Lexer {
    src: Vec<char>,
    position: usize,
    line: usize,
    column: usize,
}

impl Lexer {
    pub fn new(src: &str) -> Self {
        Self {
            src: src.chars().collect(),
            position: 0,
            line: 1,
            column: 1,
        }
    }

    fn peek(&self) -> Option<char> {
        if self.position < self.src.len() {
            Some(self.src[self.position])
        } else {
            None
        }
    }

    fn peek_next(&self) -> Option<char> {
        if self.position + 1 < self.src.len() {
            Some(self.src[self.position + 1])
        } else {
            None
        }
    }

    fn advance(&mut self) {
        let current_char = self.src.get(self.position).copied();

        if let Some(c) = current_char {
            self.position += 1;

            if c == '\n' {
                self.line += 1;
                self.column = 1;
            } else {
                self.column += 1;
            }
        }
    }

    fn skip_whitespace(&mut self) {
        while let Some(c) = self.peek() {
            if c.is_whitespace() {
                self.advance();
            } else {
                break;
            }
        }
    }

    fn read_number(&mut self) -> TokenType {
        let mut s = String::new();
        let mut is_float = false;

        while let Some(c) = self.peek() {
            if c.is_ascii_digit() {
                s.push(c);
                self.advance();
            } else if c == '.' && !is_float {
                is_float = true;
                s.push(c);
                self.advance();
            } else {
                break;
            }
        }

        if !is_float {
            let value = s.parse::<f64>().unwrap_or(0.0);
            TokenType::NombreReel { value }
        } else {
            let value = s.parse::<i64>().unwrap_or(0);
            TokenType::NombreEntier { value }
        }
    }

    fn read_string(&mut self) -> TokenType {
        let mut s = String::new();

        self.advance();

        while let Some(c) = self.peek() {
            if c == '"' {
                break;
            }

            s.push(c);
            self.advance();
        }

        self.advance();

        TokenType::TexteLitteral { value: s }
    }

    fn read_identifier(&mut self) -> TokenType {
        let mut s = String::new();

        while let Some(c) = self.peek() {
            if c.is_alphanumeric() || c == '_' {
                s.push(c);
                self.advance();
            } else {
                break;
            }
        }

        self.lookup_keyword(s)
    }

    fn lookup_keyword(&self, s: String) -> TokenType {
        // TODO
        match s.as_str() {
            "Debut" => TokenType::Debut,
            "Fin" => TokenType::Fin,
            "Si" => TokenType::Si,
            _ => TokenType::Identifiant { name: s },
        }
    }

    fn next_token(&mut self) -> Option<Token> {
        self.skip_whitespace();

        let c = self.peek().unwrap();

        let token_type = match c {
            //TODO
            '(' => {
                self.advance();
                TokenType::ParenOuvrante
            },

            '=' => {
                self.advance();

                if self.peek() == Some('=') {
                    self.advance();
                    TokenType::EgalEgal
                } else {
                    TokenType::Egal
                }
            },

            '"' => self.read_string(),

            _ => {
                if c.is_ascii_digit() {
                    self.read_number()
                } else if c.is_alphabetic() || c == '_' {
                    self.read_identifier()
                } else {
                    self.advance();
                    TokenType::Unknown { char: c }
                }
            }
        };

        Some(Token {
            token_type,
            line: self.line,
            column: self.column,
        })
    }

    pub fn tokenize(&mut self) -> Result<Vec<Token>, ExalgoError> {
        let mut tokens = Vec::new();

        while self.peek().is_some() {
            self.skip_whitespace();

            if self.peek().is_none() {
                break;
            }

            let token = self.next_token().unwrap();

            tokens.push(token);
        }

        Ok(tokens)
    }
}