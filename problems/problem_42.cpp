#include "problem_42.hpp"

#include <vector>
#include <map>

#include <iostream>
#include <fstream>

using namespace std;

#include "../Computing/StringOperations.hpp"

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
