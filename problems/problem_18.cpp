#include "problem_18.hpp"

#include <iostream>

using namespace std;

int problem_18()
{
    int tab[] = {75,95,64,17,47,82,18,35,87,10,20,04,82,47,65,19,01,23,75,03,34,88,02,77,73,07,63,67,99,65,04,28,06,16,70,92,41,41,26,56,83,40,80,70,33,41,48,72,33,47,32,37,16,94,29,53,71,44,65,25,43,91,52,97,51,14,70,11,33,28,77,73,17,78,39,68,17,57,91,71,52,38,17,14,91,43,58,50,27,29,48,63,66,04,68,89,53,67,30,73,16,69,87,40,31,04,62,98,27,23,9,70,98,73,93,38,53,60,04,23};


    for(int level = 1 ; level < 15 ; ++level)
    {
        int prevLinePos = (level-1)*(level)/2;
        int linePos = level*(level+1)/2;
        int lineSize = level + 1;

        for(int idx = 0 ; idx < lineSize ; ++idx)
        {
            int tmpL = 0;
            int tmpR = 0;

            if(idx > 0)
                tmpL = tab[idx + linePos] + tab[idx + prevLinePos - 1];

            if(idx <= prevLinePos)
                tmpR = tab[idx + linePos] + tab[idx + prevLinePos];

            if(tmpL > tmpR)
                tab[idx + linePos] = tmpL;
            else
                tab[idx + linePos] = tmpR;
        }
    }

    int level = 14;
    int linePos = level*(level+1)/2;
    int lineSize = level + 1;
    int maxval = 0;

    for(int idx = 0 ; idx < lineSize ; ++idx)
    {
        if(tab[idx + linePos] > maxval)
            maxval = tab[idx + linePos];
    }

    cout << maxval << endl;

    return 0;
}
