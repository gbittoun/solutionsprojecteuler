#include <iostream>

using namespace std;

int problem_91()
{
    long long sum = 0;

    for(int x0 = 0 ; x0 <= 50 ; ++x0)
    {
        for(int y0 = 0 ; y0 <= 50 ; ++y0)
        {
            for(int x1 = 0 ; x1 <= 50 ; ++x1)
            {
                for(int y1 = 0 ; y1 <= 50 ; ++y1)
                {
                    if( ((x0 != 0) || (y0 != 0)) && ((x1 != 0) || (y1 != 0)) && ((x0 != x1) || (y0 != y1)) )
                    {
                        int A = x0 * x0 + y0 * y0;
                        int B = x1 * x1 + y1 * y1;
                        int C = (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
                        if( (A + B == C) || (A + C == B) || (B + C == A) )
                        {
                            cout << "(" << x0 << ", " << y0 << ");" << "(" << x1 << ", " << y1 << ")" << endl;
                            ++sum;
                        }
                    }
                }
            }
        }
    }

    cout << (sum / 2) << endl;

    return 0;
}
