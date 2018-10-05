#include <iostream>
#include "TransitionTable.h"

int main()
{
    TransitionTable transitionTable;

    transitionTable.add(5).add("abcd", 5).add("cdef", 6);
}