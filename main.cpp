#include "problems/problem_63.hpp"

#include "Computing/IntegerOperations.hpp"

#include <iostream>
#include <map>
#include <vector>
#include <math.h>

using namespace std;
using namespace Computing;

void GetSqrtCoeff(long long n, vector<long long> & a)
{
    long long b = 0, c = 1, tmp = 0;
    set<pair<long long, long long> > mem;

    do
    {
        mem.insert(make_pair(b,c));

        do
        {
            tmp += c;
        }
        while((b - tmp - c) * (b - tmp - c) < n);

        a.push_back(tmp / c);

        b = tmp - b;
        c = (n - b * b) / c;
        tmp = 0;

    } while(mem.find(make_pair(b,c)) == mem.end());
}

int main()
{
    const long long n = 13;
    vector<long long> a;

    GetSqrtCoeff(n, a);

    cout << n << " : ";
    for(vector<long long>::iterator it = a.begin() ; it != a.end() ; ++it)
        cout << *it << ",";
    cout << endl;

    return 0;
}
