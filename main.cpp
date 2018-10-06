#include <iostream>
#include "TransitionTable/TransitionTable.h"

int main()
{
    TransitionTable transitionTable;

    transitionTable.add(5).add(5, "abc");
}