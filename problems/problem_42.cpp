#include "problem_42.hpp"

#include <vector>
#include <map>

namespace Computing
{
    long long ComputeStringSum(string str)
    {
        size_t s = str.size();
        const char * c = str.c_str();

        long long sum = 0;

        for(size_t idx = 0 ; idx < s ; ++idx)
        {
            sum += c[idx] - 64;
        }

        return sum;
    }
}

#include <iostream>
#include <fstream>

using namespace std;

int problem_42()
{

    ifstream f("words.txt");
    string str((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());

    f.close();

    map<long long, long long> numbers;

    while(true)
    {
        str = str.substr(str.find("\"") + 1, str.size() - (str.find("\"") + 1));
        string a = str.substr(0, str.find("\""));

        if(a.size() == 0)
            break;
        else
        {
            str = str.substr(str.find("\"") + 1, str.size() - (str.find("\"") + 1));

            ++numbers[Computing::ComputeStringSum(a)];

            cout << a << " : " << Computing::ComputeStringSum(a) << endl;
        }
    }

    long long sum = 0;

    for(long long idx = 0, jdx = 0 ; (jdx = (idx*(idx+1)/2)) <= numbers.rbegin()->first ; ++idx)
    {
        if(numbers.find(jdx) != numbers.end())
        {
            sum += numbers[jdx];
        }
    }

    cout << endl << sum << endl;

    return 0;
}
