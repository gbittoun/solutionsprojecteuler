#include "../Computing/IntegerOperations.hpp"

using namespace Computing;

int main()
{
    for(long long n = 10000 ; n < 1000000LL ; ++n)
    {
        long long result = Partition_Truncated(n);

        cout << n << " => " << result  << endl;

        if(result == 0)
            break;
    }

    return 0;
}
