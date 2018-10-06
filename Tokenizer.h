//
// Created by stoffel on 10/5/18.
//

#ifndef SIMPLIFIEDJAPANESETRANSLATOR_SCANNER_H
#define SIMPLIFIEDJAPANESETRANSLATOR_SCANNER_H

#include <string>
#include <unordered_map>
#include "Token.h"

using std::string;
using std::unordered_map;

class Tokenizer
{
protected:
    unordered_map<string, string> reservedWords;

public:
    Tokenizer() = default;
    explicit Tokenizer(unordered_map<string, string> reservedWords);

    Token tokenize(string &word);
};


#endif //SIMPLIFIEDJAPANESETRANSLATOR_SCANNER_H
