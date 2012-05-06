#ifndef FILLMATRIX_HPP
#define FILLMATRIX_HPP

#include <string>

using namespace std;

template<int N>
void FillMatrix(long long matrix[N][N], const string & str)
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
            if(col >= N)
            {
                col = 0;
                row += 1;
            }
        }
    }
}

#endif
