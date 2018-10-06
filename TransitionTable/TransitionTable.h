//
// Created by stoffel on 9/27/18.
//

#ifndef SIMPLIFIEDJAPANESETRANSLATOR_TRANSITIONTABLE_H
#define SIMPLIFIEDJAPANESETRANSLATOR_TRANSITIONTABLE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Transition.h"
#include "Transitions.h"

using std::getline;

using std::unordered_map;

class TransitionTable
{
private:
    vector<string> & splitByDelimiter(vector<string> & accumulator, string & str, char delimiter);
    string & clearWhitespace(string & str);
    int convertStringToInt(string & str);

protected:
    unordered_map<int, Transitions> transitionTable;

    bool populateFromLine(string &line);
public:
    TransitionTable() = default;
    ~TransitionTable();
    Transitions & add(int source);
    bool populateByFile(string &absPathToFile);
};


#endif //SIMPLIFIEDJAPANESETRANSLATOR_TRANSITIONTABLE_H
