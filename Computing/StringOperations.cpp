#include "StringOperations.hpp"

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
