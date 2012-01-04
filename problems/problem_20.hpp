#include <iostream>
#include <fstream>
#include <string.h>

namespace Computing
{
    using namespace std;

    template<int n>
    class FatNumber
    {
        int v[n];

        void Spread()
        {
            for(size_t idx = 0 ; idx < (sizeof(v) / sizeof(int)) - 1 ; ++idx)
            {
                if(v[idx] >= 10000)
                {
                    v[idx+1] += v[idx] / 10000;
                    v[idx] %= 10000;
                }
            }
        }

        public:

        FatNumber()
        {
            memset(v, 0, n * sizeof(int));
        }

        FatNumber & operator=(int x)
        {
            memset(v, 0, n * sizeof(int));
            v[0] = x;

            Spread();

            return *this;
        }

        FatNumber & operator+=(FatNumber<n> & x)
        {
            for(int idx = 0 ; idx < n ; ++idx)
            {
                v[idx] += x.v[idx];
            }

            Spread();

            return *this;
        }

        FatNumber & operator*=(FatNumber<n> & number)
        {
            for(size_t idx = 0 ; idx < (sizeof(v) / sizeof(int)) ; ++idx)
            {
                *this *= number.v[idx];

                Spread();
            }
        }

        FatNumber & operator*(int x)
        {
            for(size_t idx = 0 ; idx < (sizeof(v) / sizeof(int)) ; ++idx)
            {
                v[idx] *= x;
            }

            Spread();

            return *this;
        }

        FatNumber & operator=(FatNumber<n> x)
        {
            memcpy(v, x.v, sizeof(v));

            return *this;
        }

        int NbDigits() const
        {
            int ret = -1;

            for(int idx = sizeof(v) / sizeof(int) - 1 ; idx >= 0 ; --idx)
            {
                if(v[idx] != 0)
                {
                    ret = idx;
                    break;
                }
            }

            if(ret != -1)
            {
                if(v[ret] / 1000)
                    return ret*4 + 4;
                else if(v[ret] / 100)
                    return ret*4 + 3;
                else if(v[ret] / 10)
                    return ret*4 + 2;
                else
                    return ret * 4 + 1;
            }

            return ret;
        }

        void Print()
        {
            bool youcanprint = false;
            for(int idx = (sizeof(v) / sizeof(int)) - 1 ; idx >= 0 ; --idx)
            {
                if(youcanprint)
                    cout << v[idx];
                else if (v[idx] != 0)
                {
                    youcanprint = true;
                    cout << v[idx];
                }
            }
        }

        int SumOfDigits()
        {
            int sum = 0;

            for(int idx = (sizeof(v) / sizeof(int)) - 1 ; idx >= 0 ; --idx)
            {
                int d1 = v[idx] / 1000;
                int d2 = (v[idx] - d1 * 1000) / 100;
                int d3 = (v[idx] - d1 * 1000 - d2 * 100) / 10;
                int d4 = v[idx] % 10;

                sum += d1 + d2 + d3 + d4;
            }

            return sum;
        }

        bool operator<(const FatNumber<n> & number) const
        {
            for(int idx = (sizeof(v) / sizeof(int)) - 1 ; idx >= 0 ; --idx)
            {
                if(v[idx] < number.v[idx])
                    return true;
                else if (v[idx] > number.v[idx])
                    return false;
            }

            return false;
        }

        class CompareFatNumber
        {
            public :

            bool operator()(const FatNumber<n> & a, const FatNumber<n> & b)
            {
                return a < b;
            }
        };


        template<int N>
        friend fstream & operator<<(fstream & o, FatNumber<N> number);

        template<int N>
        friend ostream & operator<<(ostream & o, FatNumber<N> number);

    };

    template<int n>
    fstream & operator<<(fstream & o, FatNumber<n> number)
    {
        bool youcanprint = false;
        for(int idx = n - 1 ; idx >= 0 ; --idx)
        {
            if(youcanprint)
                o << number.v[idx];
            else if (number.v[idx] != 0)
            {
                youcanprint = true;
                o << number.v[idx];
            }
        }

        return o;
    }

    template<int n>
    ostream & operator<<(ostream & o, FatNumber<n> number)
    {
        bool youcanprint = false;
        for(int idx = n - 1 ; idx >= 0 ; --idx)
        {
            if(youcanprint)
                o << number.v[idx];
            else if (number.v[idx] != 0)
            {
                youcanprint = true;

                o << number.v[idx];
            }
        }

        return o;
    }
}
