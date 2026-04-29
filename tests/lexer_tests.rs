use exalgo_interpreter::lexer::Lexer;
use exalgo_interpreter::token::{ Token, TokenType };


#[cfg(test)]
mod lexer_tests {
    use super::*;

    #[test]
    fn test_unique_token() {
        let src = "test";
        let mut lexer = Lexer::new(src);

        let tokens = lexer.tokenize().unwrap();

        let token_type= TokenType::Identifiant { name: src.to_string() };
        let res = Token::new(token_type, 1, 4);

        assert_eq!(tokens[0], res);
    }
}