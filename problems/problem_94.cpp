#include <iostream>
#include <queue>

using namespace std;


struct Triple
{
    long long a, b, c;
};

int main()
{
    long long P = 0;

    Triple a, b, c, d;
    a.a = 3;
    a.b = 4;
    a.c = 5;

    queue<Triple> q;
    q.push(a);

    while(q.size() > 0)
    {
        a = q.front();
        q.pop();

        if ((a.a * 2 + 1 == a.c) || (a.a * 2 - 1 == a.c) || (a.b * 2 + 1 == a.c) || (a.b * 2 - 1 == a.c))
        {
            cout << a.a << ", " << a.b << ", " << a.c << endl;
        }

        if ((a.a * 2 + 1 == a.c) || (a.a * 2 - 1 == a.c))
        {
            P += a.c * 2 + 2 * a.a;
            // cout << a.c * 2 + 2 * a.a << endl;
        }

        if ((a.b * 2 + 1 == a.c) || (a.b * 2 - 1 == a.c))
        {
            P += a.c * 2 + 2 * a.b;
            // cout << a.c * 2 + 2 * a.b << endl;
        }

        b.a = 1 * a.a - 2 * a.b + 2 * a.c;
        b.b = 2 * a.a - 1 * a.b + 2 * a.c;
        b.c = 2 * a.a - 2 * a.b + 3 * a.c;

        if (((b.c * 2 - 1) * 3) < 1000000000LL)
            q.push(b);


        c.a = 1 * a.a + 2 * a.b + 2 * a.c;
        c.b = 2 * a.a + 1 * a.b + 2 * a.c;
        c.c = 2 * a.a + 2 * a.b + 3 * a.c;

        if (((c.c * 2 - 1) * 3) < 1000000000LL)
            q.push(c);


        d.a = - 1 * a.a + 2 * a.b + 2 * a.c;
        d.b = - 2 * a.a + 1 * a.b + 2 * a.c;
        d.c = - 2 * a.a + 2 * a.b + 3 * a.c;

        if (((d.c * 2 - 1) * 3) < 1000000000LL)
            q.push(d);
    }

    cout << endl << P << endl;

    return 0;
}
