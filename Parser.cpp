//
// Created by stoffel on 10/5/18.
//

#include "Parser.h"


Parser::Parser(Tokenizer &tokenizer)
{
    this->tokenizer = tokenizer;
}

bool Parser::parse(string &file)
{
    //Valid file?
    if(file.empty())
        return false;

    //Open the file
    ifstream inputFile(file);
    this->inputFile = inputFile;


}

bool Parser::nextWord(string &word, ifstream &inputFile)
{
    char currentChar;
    string currentWord = "";

    //While there are characters left in the inputFile
    while(inputFile.get(currentChar))
    {
        //Spaces or newlines demark the end of our currentWord (except if currentWord is empty)
        if(isspace(currentChar) || currentChar == '\n' || currentChar == '\r')
        {
            if(!currentWord.empty())
                break;
            continue;
        }

        //If we haven't had reason to ignore the currentChar, add it to the currentWord
        currentWord.push_back(currentChar);
    }

    //Note: its possible that word will be an empty string
    word = currentWord;
}

void Parser::matched()
{
    //If we're at the EOF, exit
    if(inputFile.eof())
        return;

    //Read the next word from the file
    string word;
    nextWord(word, this->inputFile);

    //Get its token
    token = tokenizer.tokenize(nextWord);
}

bool Parser::optional(TokenType token)
{
    if(currentToken()().getType() == token)
    {
        matched();
        return true;
    }

    return false;
}


//Clunky; refactor
bool Parser::optional(Parser::Nonterminal nonterminal)
{
    bool success = false;
    string expected;

    switch(nonterminal)
    {
        case NONTERMINAL_NOUN:
            success = currentToken().getType() == WORD1 || currentToken().getType() == PRONOUN;
            expected = "WORD1 | PRONOUN";
            break;
        case NONTERMINAL_VERB:
            success = currentToken().getType() == WORD2;
            expected = "WORD2";
            break;
        case NONTERMINAL_BE:
            success = currentToken().getType() == IS || currentToken().getType() == WAS;
            expected = "IS | WAS";
            break;
        case NONTERMINAL_TENSE:
            success = currentToken().getType() == VERBPAST
                    || currentToken().getType() == VERBPASTNEG
                    || currentToken().getType() == VERB
                    || currentToken().getType() == VERBNEG;

            expected = "VERBPAST | VERBPASTNEG | VERB | VERBNEG";
            break;
        default:
            throw std::invalid_argument("match");
    }

    if(success)
    {
        matched();
        return true;
    }

    return false;
}

bool Parser::required(TokenType token)
{
    if(!optional(token))
        throw std::invalid_argument("SyntaxErrorOne"); //Add the real exception here

    return true;
}

bool Parser::required(Parser::Nonterminal nonterminal)
{
    if(!optional(nonterminal))
        throw std::invalid_argument("SyntaxErrorOne");

    return true;
}

Token& Parser::currentToken()
{
    if(isFirst)
    {
        string word;
        nextWord(word, inputFile);
        token = tokenizer.tokenize(word);

        isFirst = false;
    }

    return token;
}

bool Parser::story()
{

}

//<s0> ::= [CONNECTOR] <noun> SUBJECT <s1>
bool Parser::matchesS0()
{
    optional(CONNECTOR);

    //If the first (or second) element isn't a non-terminal noun, that'd be a syntax error type 2
    if(optional(NONTERMINAL_NOUN)) {
        throw std::invalid_argument("SyntaxErrorTwo");
    }

    required(SUBJECT);

}

//<s1> ::= <verb> <tense> PERIOD | <noun> <s2>
bool Parser::matchesS1()
{
    if(optional(NONTERMINAL_VERB))
    {
        required(NONTERMINAL_TENSE);
        return required(PERIOD);
    }
    else if(optional(NONTERMINAL_NOUN))
    {
        if(!matchesS2())
            throw std::invalid_argument("SyntaxErrorOne");

        return true;
    }
    else
        throw std::invalid_argument("SyntaxErrorTwo");
}

//<s2> ::= <be> PERIOD | DESTINATION <verb> <tense> | OBJECT <s3>
bool Parser::matchesS2()
{
    return false;
}






