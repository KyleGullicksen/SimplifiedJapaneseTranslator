cmake_minimum_required(VERSION 3.12)
project(SimplifiedJapaneseTranslator)

set(CMAKE_CXX_STANDARD 11)

add_executable(SimplifiedJapaneseTranslator main.cpp TransitionTable/TransitionTable.cpp TransitionTable/TransitionTable.h TransitionTable/Transitions.cpp TransitionTable/Transitions.h Tokenizer.cpp Tokenizer.h Parser.cpp Parser.h Token.cpp Token.h SyntaxExceptions/SyntaxErrorOne.cpp SyntaxExceptions/SyntaxErrorOne.h SyntaxExceptions/SyntaxErrorTwo.cpp SyntaxExceptions/SyntaxErrorTwo.h)