#include <set>

namespace Sudoku
{
    using namespace std;

    struct IndexAndValues
    {
        static set<char> globals;

        bool solved;
        int row, col;
        set<char> values;

        void InitCheck();
        IndexAndValues();
    };
}
