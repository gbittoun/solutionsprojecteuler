cmake_minimum_required(VERSION 2.8)

project(utils)

file(GLOB_RECURSE computing_files "Computing/*.cpp")
file(GLOB_RECURSE io_files "IO/*.cpp")
file(GLOB_RECURSE poker_game_files "PokerGame/*.cpp")
file(GLOB_RECURSE sudoku_files "Sudoku/*.cpp")

add_library(${PROJECT_NAME}
    ${computing_files}
    ${io_files}
    ${poker_game_files}
    ${sudoku_files}
)

add_subdirectory("problems")
