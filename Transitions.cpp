//
// Created by stoffel on 9/27/18.
//

#include "Transitions.h"

Transitions &Transitions::add(int destination, string transitionChars)
{
    //is the destination valid?
    if(destination < 0)
        //throw invalid destination exception

}

int Transitions::getIndex(char ch)
{
    return tolower(ch) - 97;
}
