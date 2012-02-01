#ifndef FATNUMBER_HPP
#define FATNUMBER_HPP

#include <iostream>
#include <fstream>
#include <string.h>

namespace Computing
{
    using namespace std;

    template<int N>
    class FatNumber
    {
        int v[N];

        void Spread()
        {
            for(size_t idx = 0 ; idx < (sizeof(v) / sizeof(int)) - 1 ; ++idx)
            {
                if(v[idx] >= 1000)
                {
                    v[idx+1] += v[idx] / 1000;
                    v[idx] %= 1000;
                }
            }
        }

        public:

        FatNumber()
        {
            memset(v, 0, N * sizeof(int));
        }

        FatNumber(int a)
        {
            memset(v, 0, N * sizeof(int));
            v[0] = a;
            Spread();
        }

        FatNumber<N> & operator=(int x)
        {
            memset(v, 0, N * sizeof(int));
            v[0] = x;
            Spread();

            return *this;
        }

        FatNumber<N> & operator=(const FatNumber<N> x)
        {
            memcpy(v, x.v, sizeof(v));

            return *this;
        }

        bool operator==(const FatNumber<N> & x) const
        {
            for(int idx = 0 ; idx < N ; ++idx)
                if(v[idx] != x.v[idx])
                    return false;

            return true;
        }

        FatNumber<N> operator+(const FatNumber<N> & x) const
        {
            FatNumber<N> ret;

            for(int idx = 0 ; idx < N ; ++idx)
            {
                ret.v[idx] = v[idx] + x.v[idx];
            }

            ret.Spread();

            return ret;
        }

        FatNumber<N> operator-(const FatNumber<N> & x) const
        {
            FatNumber<N> ret;

            for(int idx = 0 ; idx < N ; ++idx)
            {
                ret.v[idx] = v[idx] - x.v[idx];
            }

            ret.Spread();

            return ret;
        }

        FatNumber<N> & operator+=(const FatNumber<N> & x)
        {
            for(int idx = 0 ; idx < N ; ++idx)
            {
                v[idx] += x.v[idx];
            }

            Spread();

            return *this;
        }

        FatNumber<N> & operator*=(const FatNumber<N> & x)
        {
            *this = *this * x;
            return *this;
        }

        FatNumber<N> operator*(const FatNumber<N> & x) const
        {
            FatNumber<N> ret;

            for(int idx = 0 ; idx < N ; ++idx)
            {
                for(int jdx = 0 ; jdx < N-idx ; ++jdx)
                {
                    ret.v[idx+jdx] += v[jdx] * x.v[idx];
                }
                ret.Spread();
            }

            return ret;
        }

        FatNumber<N> operator*(const int & x) const
        {
            FatNumber<N> ret;

            for(size_t idx = 0 ; idx < N ; ++idx)
            {
                ret.v[idx] = this->v[idx] * x;
            }

            ret.Spread();

            return ret;
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
                if(v[ret] >= 100)
                    return ret*3 + 3;
                else if(v[ret] >= 10)
                    return ret*3 + 2;
                else
                    return ret*3 + 1;
            }

            return ret;
        }

        int SumOfDigits()
        {
            int sum = 0;

            for(int idx = 0 ; idx < N ; ++idx)
            {
                int val = v[idx];

                while(val > 0)
                {
                    sum += val % 10;
                    val /= 10;
                }
            }

            return sum;
        }

        bool operator<(const FatNumber<N> & number) const
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

            bool operator()(const FatNumber<N> & a, const FatNumber<N> & b)
            {
                return a < b;
            }
        };

        template<int M>
        friend ostream & operator<<(ostream & o, const FatNumber<M> & x);

        template<int M>
        friend FatNumber<M> MakePalindrome(const FatNumber<M> & x);
    };

    template<int N>
    ostream & operator<<(ostream & o, const FatNumber<N> & x)
    {
        bool youcanprint = false;
        for(int idx = (sizeof(x.v) / sizeof(int)) - 1 ; idx >= 0 ; --idx)
        {
            if (!youcanprint && x.v[idx] != 0)
            {
                youcanprint = true;

                int printable = x.v[idx];
                if(printable >= 100)
                {
                    cout << printable / 100;printable = printable - (printable / 100) * 100;
                    cout << printable / 10;printable = printable - (printable / 10) * 10;
                    cout << printable;
                }
                else if(printable >= 10)
                {
                    cout << printable / 10;printable = printable - (printable / 10) * 10;
                    cout << printable;
                }
                else
                    cout << printable;

            }
            else if(youcanprint)
            {
                int printable = x.v[idx];
                cout << printable / 100;printable = printable - (printable / 100) * 100;
                cout << printable / 10;printable = printable - (printable / 10) * 10;
                cout << printable;
            }
        }

        if(!youcanprint)
            cout << 0;

        return o;
    }
}

#endif
