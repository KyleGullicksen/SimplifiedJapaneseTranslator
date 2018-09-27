//
// Created by stoffel on 9/27/18.
//

#ifndef SIMPLIFIEDJAPANESETRANSLATOR_TRANSITION_H
#define SIMPLIFIEDJAPANESETRANSLATOR_TRANSITION_H

#include <unordered_set>
#include <string>

using std::unordered_set;
using std::string;

class Transition
{
protected:
    int resultState = 0;
    unordered_set<char> transitionChars;

public:
    Transition(int resultState, string transitionChars);

    bool validTransitionChar(char nextChar);
    int getResultState();
};


#endif //SIMPLIFIEDJAPANESETRANSLATOR_TRANSITION_H
