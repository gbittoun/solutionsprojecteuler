#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include <stdlib.h>

using namespace std;


int main()
{
    fstream f("triangle.txt");

    vector<int> values;

    int maxlevel = 0;

    while(!f.eof())
    {
        string str;
        getline(f, str);

        ++maxlevel;
        while(true)
        {
            values.push_back(atoi(str.c_str()));

            size_t pos = str.find(' ');
            if(pos != string::npos)
                str = str.substr(pos + 1);
            else
                break;

            if(str.length() < 2)
                break;
        }
    }

    int * tab = &values[0];

    for(int level = 1 ; level < maxlevel ; ++level)
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

            if(idx + prevLinePos < linePos)
                tmpR = tab[idx + linePos] + tab[idx + prevLinePos];

            if(tmpL > tmpR)
                tab[idx + linePos] = tmpL;
            else
                tab[idx + linePos] = tmpR;
        }
    }

    int level = maxlevel - 1;
    int linePos = level*(level+1)/2;
    int lineSize = maxlevel;
    int maxval = 0;

    for(int idx = 0 ; idx < lineSize ; ++idx)
    {
        if(tab[idx + linePos] > maxval)
            maxval = tab[idx + linePos];
    }

    cout << maxval << endl;

    return 0;
}
