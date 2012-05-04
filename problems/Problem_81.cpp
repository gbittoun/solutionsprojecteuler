#include "Problem_81.hpp"

#include <fstream>

using namespace std;

void FillMatrix(long long matrix[80][80], const string & str)
{
    const char * raw = str.c_str();
    const int length = str.size();

    long long current = 0;
    int row = 0, col = 0;

    for(int i = 0 ; i < length ; ++i)
    {
        if(raw[i] >= '0' && raw[i] <= '9' )
            current = current * 10 + (raw[i] - '0');
        else
        {
            matrix[row][col] = current;
            current = 0;

            col += 1;
            if(col >= 80)
            {
                col = 0;
                row += 1;
            }
        }
    }
}

int Problem_81()
{
    ifstream f("matrix.txt");
    string str((istreambuf_iterator<char>(f)),
                 istreambuf_iterator<char>());

    f.close();

    long long mat[80][80];

    FillMatrix(mat, str);

    return 0;
}
