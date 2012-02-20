#ifndef FATNUMBER_HPP
#define FATNUMBER_HPP

#include <iostream>
#include <fstream>
#include <string.h>
#include <stack>

namespace Computing
{
    using namespace std;

    template<int N>
    class FatNumber
    {
        int v[N];
        bool isNegative;

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

        static inline void AddBuffers(const int v0[N], const int v1[N], int v_out[N])
        {
            for(int idx = 0 ; idx < N ; ++idx)
            {
                v_out[idx] = v0[idx] + v1[idx];
            }
        }

        static inline void SubstractBuffers(const int v0[N], const int v1[N], int v_out[N])
        {
            int retenue = 0;

            for(int idx = 0 ; idx < N ; ++idx)
            {
                v_out[idx] = v0[idx] - v1[idx] + (retenue ? retenue++ : 0);
                while(v_out[idx] < 0)
                {
                    cout << "pouet" << endl;

                    v_out[idx] += 1000;
                    --retenue;
                }
            }
        }

        static inline int CompareBuffers(const int v0[N], const int v1[N])
        {
            for(int idx = (sizeof(v) / sizeof(int)) - 1 ; idx >= 0 ; --idx)
            {
                if(v0[idx] < v1[idx])
                    return -1;
                else if (v0[idx] > v1[idx])
                    return 1;
            }

            return 0;
        }

        public:

        FatNumber()
        {
            memset(v, 0, N * sizeof(int));
            isNegative = false;
        }

        FatNumber(int a)
        {
            memset(v, 0, N * sizeof(int));
            v[0] = a;
            isNegative = false;
            Spread();
        }

        FatNumber<N> & operator=(long long x)
        {
            memset(v, 0, N * sizeof(int));
            v[0] = x;
            isNegative = (x < 0);

            Spread();

            return *this;
        }

        FatNumber<N> & operator=(const FatNumber<N> x)
        {
            memcpy(v, x.v, sizeof(v));
            isNegative = x.isNegative;

            return *this;
        }

        bool operator==(const FatNumber<N> & x) const
        {
            if(x.isNegative != this->isNegative)
                return false;

            for(int idx = 0 ; idx < N ; ++idx)
                if(v[idx] != x.v[idx])
                    return false;

            return true;
        }

        FatNumber<N> operator+(const FatNumber<N> & x) const
        {
            FatNumber<N> ret;

            if(this->isNegative == x.isNegative)
            {
                AddBuffers(this->v, x.v, ret.v);
                ret.isNegative = this->isNegative;
            }
            else
            {
                int comp = CompareBuffers(v, x.v);

                if(comp >= 0)
                {
                    SubstractBuffers(v, x.v, ret.v);
                    ret.isNegative = this->isNegative;
                }
                else
                {
                    SubstractBuffers(x.v, v, ret.v);
                    ret.isNegative = x.isNegative;
                }
            }

            ret.Spread();

            return ret;
        }

        FatNumber<N> operator-(const FatNumber<N> & x) const
        {
            FatNumber<N> ret;

            if(this->isNegative != x.isNegative)
            {
                AddBuffers(this->v, x.v, ret.v);
                ret.isNegative = this->isNegative;
            }
            else
            {
                int comp = CompareBuffers(v, x.v);

                if(comp >= 0)
                {
                    SubstractBuffers(v, x.v, ret.v);
                    ret.isNegative = this->isNegative;
                }
                else
                {
                    SubstractBuffers(x.v, v, ret.v);
                    ret.isNegative = !x.isNegative;
                }
            }

            ret.Spread();

            return ret;
        }

        FatNumber<N> & operator+=(const FatNumber<N> & x)
        {
            if(this->isNegative == x.isNegative)
            {
                AddBuffers(v, x.v, v);
                isNegative = this->isNegative;
            }
            else
            {
                int comp = CompareBuffers(v, x.v);

                if(comp >= 0)
                {
                    SubstractBuffers(v, x.v, v);
                    isNegative = this->isNegative;
                }
                else
                {
                    SubstractBuffers(x.v, v, v);
                    isNegative = x.isNegative;
                }
            }

            Spread();

            return *this;
        }

        FatNumber<N> & operator*=(const FatNumber<N> & x)
        {
            *this = *this * x;

            isNegative = (isNegative != x.isNegative);

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

            ret.isNegative = (isNegative != x.isNegative);

            return ret;
        }

        FatNumber<N> operator*(const long long & x) const
        {
            FatNumber<N> ret;

            for(size_t idx = 0 ; idx < N ; ++idx)
            {
                ret.v[idx] = this->v[idx] * x;
            }

            ret.Spread();

            if(x == 0)
                ret.isNegative = false;
            else
                ret.isNegative = (isNegative != (x < 0));

            return ret;
        }

        FatNumber<N> operator/(const FatNumber<N> & x) const
        {
            if(*this < x)
                return 0;
            else if(*this == x)
                return 1;

            FatNumber<N> n_inf = 1, n_sup = 2;
            stack<FatNumber<N> > s;

            while(n_sup * x < *this)
            {
                s.push(n_inf);
                n_inf = n_sup;
                n_sup *= 2;
            }

            while(!(n_inf * x == *this))
            {
                FatNumber<N> tmp = s.top();s.pop();
                tmp = tmp + n_inf;

                if(tmp * x <= *this)
                {
                    n_inf = tmp;
                }
            }

            n_inf.isNegative = (isNegative != n_inf.isNegative);

            return n_inf;
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

        bool operator<(const FatNumber<N> & x) const
        {
            int comp = CompareBuffers(this->v, x.v);

            if(comp < 0)
                return true;

            return false;
        }

        bool operator<=(const FatNumber<N> & number) const
        {
            for(int idx = (sizeof(v) / sizeof(int)) - 1 ; idx >= 0 ; --idx)
            {
                if(v[idx] < number.v[idx])
                    return true;
                else if (v[idx] > number.v[idx])
                    return false;
            }

            return true;
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
        if(x.isNegative)
            cout << "-";

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
