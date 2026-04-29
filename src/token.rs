#[derive(Debug, Clone, PartialEq)]
pub enum TokenType {
    Debut,
    Fin,
    Si,
    Alors,
    Sinon,
    FinSi,
    TantQue,
    Faire,
    FinTantQue,
    Pour,
    De,
    A,
    Pas,
    FinPour,
    Retourner,
    Fonction,
    Entier,
    Reel,
    Booleen,
    Chaine,
    Tableau,
    NombreEntier { value: i64 },
    NombreReel { value: f64 },
    TexteLitteral { value: String },
    Vrai,
    Faux,
    Plus,
    Moins,
    Multiplier,
    Diviser,
    Modulo,
    Egal,
    EgalEgal,
    Different,
    Inferieur,
    Superieur,
    InfOuEgal,
    SupOuEgal,
    Et,
    Ou,
    Non,
    Affectation,
    ParenOuvrante,
    ParenFermante,
    CrochetOuvrant,
    CrochetFermant,
    DeuxPoints,
    Virgule,
    PointVirgule,
    Identifiant { name: String },
    EOF,
    None,
    Unknown { char: char }
}

#[derive(Debug, Clone, PartialEq)]
pub struct Token {
    pub token_type: TokenType,
    pub line: usize,
    pub column: usize,
}

impl Token {
    pub fn new(token_type: TokenType, line: usize, column: usize) -> Self {
        Self {
            token_type,
            line,
            column,
        }
    }
}