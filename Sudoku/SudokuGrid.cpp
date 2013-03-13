#include <iostream>
#include <string.h>

#include "SudokuGrid.hpp"

namespace Sudoku
{
    using namespace std;

    SudokuGrid::SudokuGrid()
    {
        memset(rawGrid, 0, sizeof(rawGrid));
    }

    SudokuGrid::SudokuGrid(const char grid[9][9])
    {
        memcpy(rawGrid, grid, sizeof(rawGrid));
    }

    SudokuGrid::SudokuGrid(const SudokuGrid & grid)
    {
        memcpy(rawGrid, grid.rawGrid, sizeof(rawGrid));
    }

    SudokuGrid & SudokuGrid::operator=(const SudokuGrid & grid)
    {
        memcpy(rawGrid, grid.rawGrid, sizeof(rawGrid));
    }

    IndexAndValues SudokuGrid::GetIndexAndValues() const
    {
        IndexAndValues result;

        for (int n = 0, k = 0 ; (n < 9) || (n = 0) || (++k < 9) ; ++n)
        {
            if (!rawGrid[n][k])
            {
                result.row = n;
                result.col = k;
                break;
            }
        }

        if (result.row == -1 && result.col == -1)
        {
            result.solved = true;
            result.values = set<char>();

            return result;
        }

        for (int n = 0 ; n < 9 ; ++n)
            result.values.erase(rawGrid[result.row][n]);
        for (int n = 0 ; n < 9 ; ++n)
            result.values.erase(rawGrid[n][result.col]);
        for (int n = 0, k = 0 ; (n < 3) || (n = 0) || (++k < 3) ; ++n)
            result.values.erase(rawGrid[(result.row / 3) * 3 + n][(result.col / 3) * 3 + k]);

        return result;
    }

    void SudokuGrid::SetValue(int row, int col, char value)
    {
        rawGrid[row][col] = value;
    }

    char SudokuGrid::GetValue(int row, int col) const
    {
        return rawGrid[row][col];
    }

    ostream & operator<<(ostream & o, const SudokuGrid & grid)
    {
        for (int n = 0 ; n < 81 ; ++n)
        {
            if (n % 9 == 0 && n != 0)
                cout << endl;

            cout << (int)grid.rawGrid[n / 9][n % 9];
        }

        return o;
    }

    bool SolveSudokuGrid(SudokuGrid grid, SudokuGrid & result)
    {
        bool success = false;
        IndexAndValues info = grid.GetIndexAndValues();

        if (info.solved)
        {
            result = grid;

            return (success = true);
        }

        for (set<char>::iterator it = info.values.begin() ; it != info.values.end() ; ++it)
        {
            grid.SetValue(info.row, info.col, *it);

            success = SolveSudokuGrid(grid, result);

            if (success)
                break;
        }

        return success;
    }

    SudokuGrid ReadGrid(ifstream & file)
    {
        SudokuGrid result;
        string line;

        // Read title
        std::getline(file, line);

        cout << line << endl;

        for (int n = 0 ; n < 9 ; ++n)
        {
            std::getline(file, line);

            const char * str = line.c_str();

            for (int k = 0 ; k < 9 ; ++k)
            {
                result.SetValue(n, k, str[k] - 48);
            }
        }

        return result;
    }
}
