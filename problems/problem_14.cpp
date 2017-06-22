#include <iostream>

using namespace std;


long long iterate(long long x)
{
    if(x % 2)
    {
        return 3*x+1;
    }
    else
    {
        return x / 2;
    }
}

int main()
{
    long long maxChainNum = 0;
    long long maxChain = 0;

    long long current = 1000000;

    while(true)
    {
        long long res = current;
        long long chainSize = 0;

        while(true)
        {
            long long tmp = iterate(res);

            res = tmp;
            chainSize++;
            if(res == 1)
                break;
        }

        if(chainSize > maxChain)
        {
            maxChain = chainSize;
            maxChainNum = current;

            cout << maxChainNum << " " << maxChain << endl;
        }

        if(--current <= 2)
            break;
    }

    cout << maxChainNum << " " << maxChain << endl;

    return 0;
}
