cmake_minimum_required(VERSION 3.12)
project(SimplifiedJapaneseTranslator)

set(CMAKE_CXX_STANDARD 11)

add_executable(SimplifiedJapaneseTranslator main.cpp TransitionTable/TransitionTable.cpp TransitionTable/TransitionTable.h Transitions/TransitionFromState0.cpp Transitions/TransitionFromState0.h TransitionTable/Transitions.cpp TransitionTable/Transitions.h Scanner.cpp Scanner.h Parser.cpp Parser.h Token.cpp Token.h)