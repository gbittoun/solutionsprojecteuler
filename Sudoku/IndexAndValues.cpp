#include "IndexAndValues.hpp"

namespace Sudoku
{
    void IndexAndValues::InitCheck()
    {
        if (IndexAndValues::globals.size() == 0)
        {
            for (int n = 1 ; n <= 9 ; ++n)
                IndexAndValues::globals.insert(n);

            values = IndexAndValues::globals;
        }
    }

    IndexAndValues::IndexAndValues():
        solved(false),
        row(-1),
        col(-1),
        values(IndexAndValues::globals)
    {
        InitCheck();
    }

    set<char> IndexAndValues::globals;
};
