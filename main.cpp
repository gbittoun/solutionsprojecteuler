#include "problems/problem_2.hpp"
#include "problems/problem_3.hpp"
#include "problems/problem_4.hpp"
#include "problems/problem_7.hpp"
#include "problems/problem_9.hpp"
#include "problems/problem_10.hpp"
#include "problems/problem_11.hpp"
#include "problems/problem_12.hpp"
#include "problems/problem_13.hpp"
#include "problems/problem_14.hpp"
#include "problems/problem_15.hpp"
#include "problems/problem_16.hpp"
#include "problems/problem_17.hpp"
#include "problems/problem_18.hpp"
#include "problems/problem_19.hpp"
#include "problems/problem_20.hpp"
#include "problems/problem_21.hpp"
#include "problems/problem_22.hpp"
#include "problems/problem_23.hpp"
#include "problems/problem_24.hpp"
#include "problems/problem_25.hpp"
#include "problems/problem_26.hpp"
#include "problems/problem_27.hpp"
#include "problems/problem_28.hpp"
#include "problems/problem_29.hpp"
#include "problems/problem_30.hpp"
#include "problems/problem_31.hpp"
#include "problems/problem_32.hpp"
#include "problems/problem_33.hpp"
#include "problems/problem_34.hpp"
#include "problems/problem_35.hpp"

using namespace std;
using namespace Computing;

struct Vector
{
    long long x,y;

    Vector operator+(Vector a)
    {
        Vector v;
        v.x = x + a.x;
        v.y = y + a.y;

        return v;
    }
};

int main()
{
    long long level = 1000000;

    size_t size_u = 2, size_v = 3;

    Vector * u = new Vector[2];
    Vector * v = new Vector[3];

    u->x = 1, u->y = 0;
    (u+1)->x = 1, (u+1)->y = 1;

    long long count = 1;

    long long idx = 0, jdx = 0;

    long long max = 0;

    while(true)
    {
        if(idx < size_u - 1)
        {
            v[jdx]     = u[idx];
            v[jdx + 1] = u[idx] + u[idx + 1];
            v[jdx + 2] = u[idx + 1];

            if(v[jdx + 1].x > max)
            {
                max = v[jdx + 1].x;
                cout << max << endl;
            }
            else if(v[jdx + 1].y > max)
            {
                max = v[jdx + 1].y;
                cout << max << endl;
            }

            ++idx;
            ++++jdx;
        }
        else
        {
            delete[] u;
            size_u = size_v;
            u = v;

            size_v = 2 * size_u - 1;
            v = new Vector[size_v];

            cout << "size_v = " << size_v << endl;

            idx = 0;
            jdx = 0;


            if(max > 100000000)
                break;
        }
    }

    delete[] u;
    delete[] v;

    return 0;
}
