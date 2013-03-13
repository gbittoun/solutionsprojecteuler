#include <iostream>
#include <fstream>

#include "../Sudoku/SudokuGrid.hpp"

#include "problem_96.hpp"

using namespace std;
using namespace Sudoku;

int problem_96()
{
    ifstream infile("sudoku.txt");
    SudokuGrid grid, result;

    int sum = 0;

    for (int i = 0 ; i < 50 ; ++i)
    {
        grid = ReadGrid(infile);
        cout << grid << endl;
        SolveSudokuGrid(grid, result);
        cout << endl << result << endl << endl;

        sum += result.GetValue(0, 0) * 100 + result.GetValue(0, 1) * 10 + result.GetValue(0, 2);
    }

    cout << sum << endl;

    return 0;
}
