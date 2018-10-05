cmake_minimum_required(VERSION 3.12)
project(SimplifiedJapaneseTranslator)

set(CMAKE_CXX_STANDARD 11)

add_executable(SimplifiedJapaneseTranslator main.cpp State.cpp State.h TransitionTable.cpp TransitionTable.h Transition.cpp Transition.h Transitions/TransitionFromState0.cpp Transitions/TransitionFromState0.h Transitions.cpp Transitions.h)