#include <iostream>
#include <set>

using namespace std;


int main()
{
    set<long long> P, H;
    long long n = 1;
    int count = 0;

    while(true)
    {
        long long t = n*(n+1)/2;
        long long p = n*(3*n-1)/2;
        long long h = n*(2*n-1);

        P.insert(p);
        H.insert(h);

        if(P.find(t) != P.end() && H.find(t) != H.end())
        {
            cout << t << endl;

            if(++count >= 3)
                break;
        }

        ++n;
    }

    return 0;
}
