#include <iostream>
#include <set>

using namespace std;


int main()
{
    set<long long> p;

    for(long long idx = 1 ; idx < 10000; ++idx)
    {
        p.insert( (idx * (3*idx - 1)) / 2 );
    }

    long long iter = 0;

    set<long long>::iterator it0 = p.begin();
    while(it0 != p.end())
    {
        set<long long>::iterator it1 = p.begin();
        while(it1 != p.end())
        {
            if(p.find(*it0 + *it1) != p.end() && p.find(*it0 - *it1) != p.end())
            {
                cout << *it0 << " " << *it1 << " : " << *it0 - *it1 << endl;
                goto TheEnd;
            }

            ++it1;

            ++iter;
            if(iter % 100000 == 0)
                cout << iter << endl;
        }
        ++it0;
    }

TheEnd:

    return 0;
}
