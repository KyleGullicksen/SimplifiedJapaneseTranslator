//
// Created by stoffel on 9/27/18.
//

#ifndef SIMPLIFIEDJAPANESETRANSLATOR_TRANSITIONS_H
#define SIMPLIFIEDJAPANESETRANSLATOR_TRANSITIONS_H

#include <string>
#include <vector>
#include <ctype.h>


using std::string;
using std::vector;

class Transitions
{
protected:
    vector<int> transitions; //Char (converted to a lowercase char's ASCII code -> valid set of integers (representing dest states)
    int getIndex(char ch);

public:
    Transitions();
    virtual Transitions & add(int destination, string transitionChars);
    virtual Transitions & add(int destination, char transitionChar);
    int getTransition(char ch);
};


#endif //SIMPLIFIEDJAPANESETRANSLATOR_TRANSITIONS_H
