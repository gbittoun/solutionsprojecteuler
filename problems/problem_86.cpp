#include "../Computing/Matrix.hpp"

#include <queue>
#include <map>

using namespace std;
using namespace Computing;


int main()
{
    const int A[3][3] = { { 1, -2, 2}, { 2, -1, 2}, { 2, -2, 3} };
    const int B[3][3] = { { 1,  2, 2}, { 2,  1, 2}, { 2,  2, 3} };
    const int C[3][3] = { {-1,  2, 2}, {-2,  1, 2}, {-2,  2, 3} };

    vect3<long long> v = vect3<long long>(3, 4, 5);

    queue<vect3<long long> > q;

    q.push(v);

    map<long long, long long> m;

#define MAX_VALUE 1000000LL

    while(q.size() > 0)
    {
        v = q.front();
        q.pop();

        long long max = (v.x >= v.y && v.x >= v.z) ? v.x : (v.y >= v.z && v.y >= v.x) ? v.y : v.z;
        long long min = (v.x <= v.y && v.x <= v.z) ? v.x : (v.y <= v.z && v.y <= v.x) ? v.y : v.z;
        long long med = (v.x >  min && v.x <  max) ? v.x : (v.y >  min && v.y <  max) ? v.y : v.z;

        if(min > MAX_VALUE && med > MAX_VALUE && max > MAX_VALUE)
            continue;

        for(long long i = 1 ; i * med <= MAX_VALUE ; ++i)
        {
            m[i * med] +=  i * min / 2;

            if(med <= 2 * min)
            {
                m[i * min] += i * (2 * min - med) / 2 + 1;
            }
        }

        q.push(A * v);
        q.push(B * v);
        q.push(C * v);
    }

    long long cumul = 0;

    for(map<long long, long long>::iterator it = m.begin() ; cumul <= MAX_VALUE ; ++it)
    {
        cumul += it->second;
        cout << it->first << " " << cumul << endl;
    }

    return 0;
}
