#include "problem_81.hpp"

#include <iostream>
#include <fstream>

using namespace std;

#define MATRIX_SIZE 80

void FillMatrix(long long matrix[MATRIX_SIZE][MATRIX_SIZE], const string & str)
{
    const char * raw = str.c_str();
    const int length = str.size();

    long long current = 0;
    int row = 0, col = 0;
    bool incomingNumber = false;

    for(int i = 0 ; i < length ; ++i)
    {
        if(raw[i] >= '0' && raw[i] <= '9' )
        {
            incomingNumber = true;
            current = current * 10 + (raw[i] - '0');
        }
        else if (incomingNumber)
        {
            matrix[row][col] = current;
            current = 0;
            incomingNumber = false;

            col += 1;
            if(col >= MATRIX_SIZE)
            {
                col = 0;
                row += 1;
            }
        }
    }
}

int problem_81()
{
    ifstream f("matrix.txt");
    string str((istreambuf_iterator<char>(f)),
                 istreambuf_iterator<char>());

    f.close();

    long long mat[MATRIX_SIZE][MATRIX_SIZE];

    FillMatrix(mat, str);

    // Parsing matrix from left to right
    for(int i = 1 ; i < MATRIX_SIZE ; ++i)
    {
        for(int j = 0 ; j <= i ; ++j)
        {
            //cout << (i-j) << " " << j << endl;

            if(j == 0)
                mat[i - j][j] += mat[i - j - 1][j];
            else if(j == i)
                mat[i - j][j] += mat[i - j][j - 1];
            else
                mat[i - j][j] += ((mat[i - j - 1][j] < mat[i - j][j - 1]) ? mat[i - j - 1][j] : mat[i - j][j - 1]);
        }
    }

    // Parsing matrix from right to left
    for(int i = MATRIX_SIZE - 2 ; i >= 0 ; --i)
    {
        for(int j = 0 ; j <= MATRIX_SIZE - 1 - i ; ++j)
        {
            //cout << (i + j) << " " << (MATRIX_SIZE - 1 - j) << endl;

            if((i + j) == (MATRIX_SIZE - 1))
                mat[i + j][MATRIX_SIZE - 1 - j] += mat[i + j][MATRIX_SIZE - 1 - j + 1];
            else if ((MATRIX_SIZE - 1 - j) == (MATRIX_SIZE - 1))
                mat[i + j][MATRIX_SIZE - 1 - j] += mat[i + j + 1][MATRIX_SIZE - 1 - j];
            else
                mat[i + j][MATRIX_SIZE - 1 - j] += (mat[i + j + 1][MATRIX_SIZE - 1 - j] < mat[i + j][MATRIX_SIZE - 1 - j + 1]) ? mat[i + j + 1][MATRIX_SIZE - 1 - j] : mat[i + j][MATRIX_SIZE - 1 - j + 1];
        }
    }

    long long min = 0x7fffffffffffffffLL;

    for(int i = 0 ; i < MATRIX_SIZE - 1 ; ++i)
    {
        min = (min < mat[MATRIX_SIZE - 1 - i][i]) ? min : mat[MATRIX_SIZE - 1 - i][i];
    }

    cout << min << endl;

    return 0;
}
