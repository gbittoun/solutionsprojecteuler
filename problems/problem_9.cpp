#include <iostream>

using namespace std;

int main()
{
    long a = 0, b = 0, c = 0;

    for(a = 1 ; a < 10000 ; ++a)
    {
        long up = 1000000L - 2000L*a;
        long down = -2L*a + 2000L;

        if((up % down) == 0)
        {
            b = up / down;
            c = 1000L - a - b;
            break;
        }
    }

    cout << a << " " << b << " " << c << endl;
    cout << a*a << " " << b*b << " " << c*c << endl;

    return 0;
}
