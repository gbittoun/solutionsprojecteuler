#include <set>

namespace Computing
{
    using namespace std;

    set<int> GetDivisors(int N);

    template<typename T>
    T GetSum(set<T> val)
    {
        T ret = 0;

        typename set<T>::iterator it = val.begin();
        for(; it != val.end() ; ++it)
        {
            ret += *it;
        }

        return ret;
    }

    int problem_23();
}
