//
// Created by stoffel on 10/5/18.
//

#include "Tokenizer.h"

Token Tokenizer::tokenize(string &word)
{
    if(word.empty())
        return Token(word, ERROR);

    //Period?

    return Token(word, NONE);

}

Tokenizer::Tokenizer(unordered_map<string, string> reservedWords)
{

}
