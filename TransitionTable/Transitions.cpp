//
// Created by stoffel on 9/27/18.
//

#include "Transitions.h"

Transitions &Transitions::add(int destination, string transitionChars)
{
    for (int index = 0; index < transitionChars.size(); ++index)
        this->add(destination, transitionChars[index]);

    return *this;
}

int Transitions::getIndex(char ch)
{
    return tolower(ch) - 97;
}

int Transitions::getTransition(char ch)
{
    int charIndex = this->getIndex(ch);
    int destState = this->transitions[charIndex];

    if(destState == 0)
        return -1; //Not found flag
    else
        return destState;
}

Transitions::Transitions()
{
    transitions.reserve(26);
}

Transitions &Transitions::add(int destination, char transitionChar)
{
    this->transitions[getIndex(transitionChar)] = destination;
    return *this;
}
