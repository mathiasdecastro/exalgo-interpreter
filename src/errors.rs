use thiserror::Error;

#[derive(Debug, Error)]
pub enum ExalgoError {
    #[error("Lexical error at {line}, {column}: {message}")]
    LexicalError {
        line: usize,
        column: usize,
        message: String
    },
}