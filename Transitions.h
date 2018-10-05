//
// Created by stoffel on 9/27/18.
//

#ifndef SIMPLIFIEDJAPANESETRANSLATOR_TRANSITIONS_H
#define SIMPLIFIEDJAPANESETRANSLATOR_TRANSITIONS_H

#include <string>
#include <vector>
#include <unordered_set>
#include <ctype.h>

#include "Transition.h"

using std::string;
using std::vector;
using std::unordered_set;

class Transitions
{
protected:
    vector<unordered_set<int>> transitions; //Char (converted to a lowercase char's ASCII code -> valid set of integers (representing dest states)
    int getIndex(char ch);

public:
    Transitions & add(int destination, string transitionChars);
};


#endif //SIMPLIFIEDJAPANESETRANSLATOR_TRANSITIONS_H
