//
// Created by stoffel on 10/5/18.
//

#include "Token.h"

TokenType Token::getType() const
{
    return type;
}

const string &Token::getWord() const
{
    return word;
}

Token::Token(string word, TokenType type)
{
    this->word = word;
    this->type = type;
}
