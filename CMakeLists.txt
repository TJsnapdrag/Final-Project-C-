cmake_minimum_required(VERSION 3.30)
project(Final_Project_C_)

set(CMAKE_CXX_STANDARD 14)

include_directories()

add_executable(Final_Project_C_
    carddeck.h
    games.h
    main.h
    player.h

    blackjack.cpp
    carddeck.cpp
    casino_war.cpp
    main.cpp
)
