#include <iostream>
#include <set>

using namespace std;


int DivSum(int x)
{
    int sum = 0;

    for (int idx = x/2 ; idx >= 1 ; --idx)
    {
        if(x % idx == 0)
            sum += idx;
    }

    return sum;
}


int main()
{
    set<int> amis;

    for(int idx = 2 ; idx < 10000 ; ++idx)
    {
        if(amis.find(idx) == amis.end())
        {
            int ds = DivSum(idx);
            if(ds != idx && DivSum(ds) == idx)
            {
                amis.insert(idx);
                amis.insert(ds);
            }
        }
    }

    int sum = 0;

    set<int>::iterator it = amis.begin();
    for(; it != amis.end() ; ++it)
    {
        sum += *it;
    }

    cout << sum << endl;

    return 0;
}
