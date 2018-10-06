//
// Created by stoffel on 9/27/18.
//

#include "TransitionTable.h"

Transitions &TransitionTable::nextState()
{

}

Transitions &TransitionTable::add(int source)
{
    //Do we have a row for this source?
    if(this->transitionTable.find(source) == this->transitionTable.end())
        this->transitionTable[source] = *(new Transitions());

    //Get the source's row
    return this->transitionTable[source];
}


//CSV, with 1

//Format: <src>, <dest>, (both ints) <transition chars> (ended by newline)

bool TransitionTable::populateByFile(string &absPathToFile)
{
    //Open the file
    std::ifstream input(absPathToFile);

    //Read the contents of the file line by line
    for(string line; getline(input, line))
        populateFromLine(line);

    //close the file
    input.close();
}

//Format: <src>, <dest>, (both ints) <transition chars> (ended by newline)
bool TransitionTable::populateFromLine(string &line)
{
    vector<string> commaSeperatedValues;
    splitByDelimiter(commaSeperatedValues, line, ',');

    if(commaSeperatedValues.size() != 3)
    {
        //GAH BAD ROW
        return false;
    }

    //index 0: src
    int source = convertStringToInt(clearWhitespace(commaSeperatedValues[0]);

    //index 1: dest
    int dest = convertStringToInt(clearWhitespace(commaSeperatedValues[1]);

    //index 2: transition chars (store as string)
    string transitionChars = commaSeperatedValues[2];

    //Get the row in this table that corresponds to the given source
    Transitions & sourceRow = this->add(source);

    //Add the dest to the source row
    sourceRow.add(dest, transitionChars);

    return true;
}

vector<string> &TransitionTable::splitByDelimiter(vector<string> &accumulator, string &str, char delimiter)
{
    char ch;
    string currentSubString;

    for (int index = 0; index < str.size(); ++index)
    {
        ch = str[index];

        if(ch == delimiter)
        {
            accumulator.push_back(currentSubString);
            currentSubString.clear();
            continue;
        }

        currentSubString.push_back(ch);
    }

    return accumulator;
}

string &TransitionTable::clearWhitespace(string &str)
{
    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());
}

int TransitionTable::convertStringToInt(string &str)
{
    std::stringstream stream(str);

    int value = 0;
    stream >> value;

    return value;
}

TransitionTable::~TransitionTable()
{
//    for(std::pair<int, Transitions> element : this->transitionTable)
//        delete element.second;

//Gotta delete those transitions objects...
}





//dtor, clear those rows