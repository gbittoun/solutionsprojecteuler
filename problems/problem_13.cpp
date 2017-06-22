#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    unsigned char a[64];
    memset(a,0,sizeof(a) / sizeof(char));

    fstream f("problem_13.txt");
    string line;

    while(getline(f, line))
    {
        unsigned char * ptr = a;
        string::reverse_iterator rit = line.rbegin();
        while(rit != line.rend())
        {
            *ptr += (*rit) - 48;
            if(*ptr >= 10)
            {
                *ptr -= 10;
                *(ptr + 1) += 1;
            }

            ++rit;
            ++ptr;
        }
    }

    for(int idx = 53 ; idx >= 0 ; --idx)
        cout << (int)a[idx];

    cout << endl;

    f.close();

    return 0;
}
