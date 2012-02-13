#include "problem_75.hpp"

#include "../Computing/Matrix.hpp"

#include <map>
#include <queue>

using namespace std;
using namespace Computing;

int problem_75()
{
    int A[3][3] = { { 1, -2, 2}, { 2, -1, 2}, { 2, -2, 3}};
    int B[3][3] = { { 1,  2, 2}, { 2,  1, 2}, { 2,  2, 3}};
    int C[3][3] = { {-1,  2, 2}, {-2,  1, 2}, {-2,  2, 3}};

    map<long long, int> perimeters;
    queue<vect3<long long> > q;

    q.push(vect3<long long>(3, 4, 5));

    long long count = 0;

    while(true)
    {
        vect3<long long> v = q.front();
        q.pop();

        long long p = v.x + v.y + v.z;
        for(long long n = 1 ; p * n < 1500000LL ; ++n)
            ++perimeters[p * n];

        vect3<long long> v0 = A*v;
        vect3<long long> v1 = B*v;
        vect3<long long> v2 = C*v;

        if(v0.x + v0.y + v0.z <= 1500000LL)
        {
            q.push(v0);
        }

        if(v1.x + v1.y + v1.z <= 1500000LL)
        {
            q.push(v1);
        }

        if(v2.x + v2.y + v2.z <= 1500000LL)
        {
            q.push(v2);
        }

        if(++count % 1000000)
            cout << q.size() << endl;

        if(q.size() == 0)
            break;
    }

    long long sum = 0;

    for(map<long long, int>::iterator it = perimeters.begin() ; it != perimeters.end() ; ++it)
    {
        if(it->second == 1)
        {
            cout << it->first << endl;
            ++sum;
        }
    }

    cout << endl << sum << endl;

    return 0;
}

