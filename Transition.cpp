//
// Created by stoffel on 9/27/18.
//

#include "Transition.h"

Transition::Transition(int resultState, string transitionChars)
{
    this->resultState = resultState;

    for (int index = 0; index < transitionChars.length(); ++index) {
        this->transitionChars.insert(transitionChars[index]);
    }
}

bool Transition::validTransitionChar(char nextChar)
{
    return this->transitionChars.find(nextChar) != this->transitionChars.end();
}

int Transition::getResultState()
{
    return this->resultState;
}
