//
// Created by stoffel on 9/27/18.
//

#ifndef SIMPLIFIEDJAPANESETRANSLATOR_TRANSITIONTABLE_H
#define SIMPLIFIEDJAPANESETRANSLATOR_TRANSITIONTABLE_H

#include <vector>
#include <jmorecfg.h>
#include "Transition.h"

using std::vector;

class TransitionTable
{
private:
    vector<vector<Transition>> transitionTable;

protected:
    vector<Transition> & getTransitionsForState(int state);

public:
    Transition & add(Transition & transition, int state);
    boolean remove(Transition & transition, int state);

    int transition(int currentState, char nextChar);
};


#endif //SIMPLIFIEDJAPANESETRANSLATOR_TRANSITIONTABLE_H
