//
// Created by stoffel on 10/5/18.
//

#ifndef SIMPLIFIEDJAPANESETRANSLATOR_TOKEN_H
#define SIMPLIFIEDJAPANESETRANSLATOR_TOKEN_H

enum TokenType {
    ERROR,
    WORD1,
    WORD2,
    PERIOD,
    VERB,
    VERBNEG,
    VERBPAST,
    VERBPASTNEG,
    IS,
    WAS,
    OBJECT,
    SUBJECT,
    DESTINATION,
    PRONOUN,
    CONNECTOR,
    EOFM,
    NONE
};

#include <string>

using std::string;

class Token
{
protected:
    TokenType type = NONE;
    string word = "";

public:
    Token(string word, TokenType type);
    TokenType getType() const;
    const string & getWord() const;
};


#endif //SIMPLIFIEDJAPANESETRANSLATOR_TOKEN_H
