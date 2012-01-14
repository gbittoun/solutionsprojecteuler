#include <map>

namespace Computing
{
    using namespace std;

    void Decompose(long long n, set<long long> & primes, map<long long, int> & pd);
    void DumpDecomposition(map<long long, int> & pd);
}

int problem_47();
