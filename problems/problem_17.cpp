#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;


int main()
{
    map<int, string> numstr;
    numstr[1] = "one";
    numstr[2] = "two";
    numstr[3] = "three";
    numstr[4] = "four";
    numstr[5] = "five";
    numstr[6] = "six";
    numstr[7] = "seven";
    numstr[8] = "eight";
    numstr[9] = "nine";
    numstr[10] = "ten";
    numstr[11] = "eleven";
    numstr[12] = "twelve";
    numstr[13] = "thirteen";
    numstr[14] = "fourteen";
    numstr[15] = "fifteen";
    numstr[16] = "sixteen";
    numstr[17] = "seventeen";
    numstr[18] = "eighteen";
    numstr[19] = "nineteen";
    numstr[20] = "twenty";
    numstr[30] = "thirty";
    numstr[40] = "forty";
    numstr[50] = "fifty";
    numstr[60] = "sixty";
    numstr[70] = "seventy";
    numstr[80] = "eighty";
    numstr[90] = "ninety";
    numstr[100] = "hundred";
    numstr[1000] = "thousand";

    fstream f("problem_17.txt", ios::out);

    int size = 0;

    for(int idx = 1 ; idx <= 1000 ; ++idx)
    {
        string str;

        if(int d1 = idx / 1000)
        {
            str += numstr[d1] + numstr[1000];
        }

        bool useAnd = false;
        if(int d2 = (idx - (idx / 1000) * 1000) / 100)
        {
            str += numstr[d2] + numstr[100];
            useAnd = true;
        }

        if(int d3 = idx % 100 )
        {
            if(useAnd)
                str += "and";

            if(d3 >= 20)
                str += numstr[(d3 / 10) * 10] + numstr[d3 % 10];
            else
                str += numstr[d3];
        }

        size += str.length();
        f << str << endl;
    }

    f.close();

    cout << size << endl;

    return 0;
}
