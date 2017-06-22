#include "../IO/FillMatrix.hpp"

#include <fstream>
#include <iostream>

const long long inf = 0x7fffffffffffffLL;

int main()
{
    ifstream f("matrix.txt");
    string str((istreambuf_iterator<char>(f)),
                 istreambuf_iterator<char>());

    f.close();

#define MATRIX_SIZE 80
    long long mat[MATRIX_SIZE][MATRIX_SIZE];

    FillMatrix(mat, str);

    long long testMatrix[MATRIX_SIZE][MATRIX_SIZE];

    for(int i = 0 ; i < MATRIX_SIZE * MATRIX_SIZE; ++i)
        testMatrix[i / MATRIX_SIZE][i % MATRIX_SIZE] = inf;

    for(int i = 0 ; i < MATRIX_SIZE; ++i)
        testMatrix[i][0] = mat[i][0];

    int row = 0, col = 0;

    long long minVal = inf;

    bool nothingModified = true;

    while(true)
    {
        if(row == 0 && col == 0)
            nothingModified = true;
        if(row == MATRIX_SIZE - 1 && col == MATRIX_SIZE - 1 && nothingModified)
            break;

        if(row > 0)
        {
            if(testMatrix[row][col] > testMatrix[row - 1][col] + mat[row][col])
            {
                testMatrix[row][col] = testMatrix[row - 1][col] + mat[row][col];
                nothingModified = false;
            }
        }

        if(row < MATRIX_SIZE - 1)
        {
            if(testMatrix[row][col] > testMatrix[row + 1][col] + mat[row][col])
            {
                testMatrix[row][col] = testMatrix[row + 1][col] + mat[row][col];
                nothingModified = false;
            }
        }

        if(col > 0)
        {
            if(testMatrix[row][col] > testMatrix[row][col - 1] + mat[row][col])
            {
                testMatrix[row][col] = testMatrix[row][col - 1] + mat[row][col];
                nothingModified = false;
            }
        }

        if(col == MATRIX_SIZE - 1)
        {
            if(minVal > testMatrix[row][col])
            {
                minVal = testMatrix[row][col];
                cout << minVal << endl;
            }
        }

        col += 1;
        if(col == MATRIX_SIZE)
        {
            row = (row + 1) % MATRIX_SIZE;
            col = 0;
        }
    }

    return 0;
}

