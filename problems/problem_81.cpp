#include "problem_81.hpp"
#include "../IO/FillMatrix.hpp"

#include <iostream>
#include <fstream>

using namespace std;

#define MATRIX_SIZE 80

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
