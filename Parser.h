//
// Created by stoffel on 10/5/18.
//

#ifndef SIMPLIFIEDJAPANESETRANSLATOR_PARSER_H
#define SIMPLIFIEDJAPANESETRANSLATOR_PARSER_H

#include <fstream>

#include "Tokenizer.h"

using std::ifstream;


class Parser
{
private:
    enum Nonterminal
    {
        NONTERMINAL_NOUN,
        NONTERMINAL_VERB,
        NONTERMINAL_BE,
        NONTERMINAL_TENSE
    };

    bool isFirst = true;

    bool story();
    bool matchesS0();
    bool matchesS1();
    bool matchesS2();

protected:
    Tokenizer tokenizer;
    ifstream &inputFile;
    Token token;

    bool optional(TokenType token);
    bool optional(Nonterminal nonterminal);

    bool required(TokenType token);
    bool required(Nonterminal nonterminal);

    void nextWord(string & word, ifstream &inputFile);
    Token & currentToken();

    void matched();

public:
    explicit Parser(Tokenizer & tokenizer);
    bool parse(string & file);
};


#endif //SIMPLIFIEDJAPANESETRANSLATOR_PARSER_H
