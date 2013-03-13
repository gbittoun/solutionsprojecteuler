#include <fstream>

#include "IndexAndValues.hpp"

namespace Sudoku
{
    class SudokuGrid
    {
        char rawGrid[9][9];
    public:

        SudokuGrid();
        SudokuGrid(const char grid[9][9]);
        SudokuGrid(const SudokuGrid & grid);

        SudokuGrid & operator=(const SudokuGrid & grid);

        IndexAndValues GetIndexAndValues() const;

        void SetValue(int row, int col, char value);
        char GetValue(int row, int col) const;

        friend ostream & operator<<(ostream & o, const SudokuGrid & grid);
    };

    bool SolveSudokuGrid(SudokuGrid grid, SudokuGrid & result);
    SudokuGrid ReadGrid(ifstream & file);
}
