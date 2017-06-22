#include <iostream>
#include <set>

using namespace std;


void GetDigits(int number, int & r0, int & r1, int & r2)
{
    r0 = number % 10;
    number /= 10;

    r1 = number % 10;
    number /= 10;

    r2 = number % 10;
}

int main()
{
    long long sum = 0;

    for(int i0 = 1, j0 = 0 ; (j0 = 2*i0) < 1000 ; ++i0)
    {
        int r0, r1, r2;
        GetDigits(j0, r0, r1, r2);

        set<int> d0;
        d0.insert(r0);
        d0.insert(r1);
        d0.insert(r2);

        if(d0.size() != 3)
            continue;

        int x0 = r0;
        int y0 = r1;

        for(int i1 = 1, j1 = 0 ; (j1 = 3*i1) < 1000 ; ++i1)
        {
            GetDigits(j1, r0, r1, r2);

            if(x0 != r1 || y0 != r2)
                continue;

            if(d0.find(r0) != d0.end())
                continue;

            set<int> d1(d0);
            d1.insert(r0);

            int x1 = r0;
            int y1 = r1;

            for(int i2 = 1, j2 = 0 ; (j2 = 5*i2) < 1000 ; ++i2)
            {
                GetDigits(j2, r0, r1, r2);

                if(x1 != r1 || y1 != r2)
                    continue;

                if(d1.find(r0) != d1.end())
                    continue;

                set<int> d2(d1);
                d2.insert(r0);

                int x2 = r0;
                int y2 = r1;

                for(int i3 = 1, j3 = 0 ; (j3 = 7*i3) < 1000 ; ++i3)
                {
                    GetDigits(j3, r0, r1, r2);

                    if(x2 != r1 || y2 != r2)
                        continue;

                    if(d2.find(r0) != d2.end())
                        continue;

                    set<int> d3(d2);
                    d3.insert(r0);

                    int x3 = r0;
                    int y3 = r1;

                    for(int i4 = 1, j4 = 0 ; (j4 = 11*i4) < 1000 ; ++i4)
                    {
                        GetDigits(j4, r0, r1, r2);

                        if(x3 != r1 || y3 != r2)
                            continue;

                        if(d3.find(r0) != d3.end())
                            continue;

                        set<int> d4(d3);
                        d4.insert(r0);

                        int x4 = r0;
                        int y4 = r1;

                        for(int i5 = 1, j5 = 0 ; (j5 = 13*i5) < 1000 ; ++i5)
                        {
                            GetDigits(j5, r0, r1, r2);

                            if(x4 != r1 || y4 != r2)
                                continue;

                            if(d4.find(r0) != d4.end())
                                continue;

                            set<int> d5(d4);
                            d5.insert(r0);

                            int x5 = r0;
                            int y5 = r1;

                            for(int i6 = 1, j6 = 0 ; (j6 = 17*i6) < 1000 ; ++i6)
                            {
                                GetDigits(j6, r0, r1, r2);

                                if(x5 != r1 || y5 != r2)
                                    continue;

                                if(d5.find(r0) != d5.end())
                                    continue;

                                set<int> d6(d5);
                                d6.insert(r0);

                                int x6 = r0;
                                int y6 = r1;

                                long long result = j0;
                                result = result * 10 + x1;
                                result = result * 10 + x2;
                                result = result * 10 + x3;
                                result = result * 10 + x4;
                                result = result * 10 + x5;
                                result = result * 10 + x6;

                                int total = 1+2+3+4+5+6+7+8+9;
                                total -= j0/100+j1/100+j2/100+j3/100+j4/100+j5/100+j6/100+x6+y6;

                                result += total * 1000000000LL;

                                sum += result;

                                cout << j0 << "," << j1 << "," << j2 << "," << j3 << "," << j4 << "," << j5 << "," << j6 << " : " << result << " " << total << endl;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << endl << sum << endl;

    return 0;
}
