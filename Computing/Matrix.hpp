#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

namespace Computing
{
    using namespace std;

    template<typename T>
    struct vect3
    {
        T x, y, z;

        vect3() :
            x(0),
            y(0),
            z(0)
        {
        }

        vect3(T _x, T _y, T _z) :
            x(_x),
            y(_y),
            z(_z)
        {
        }

        vect3(const vect3 & _v) :
            x(_v.x),
            y(_v.y),
            z(_v.z)
        {
        }
    };

    template<typename T>
    vect3<T> operator*(const int M[3][3], const vect3<T> & v)
    {
        vect3<T> ret;

        ret.x = v.x * M[0][0] + v.y * M[0][1] + v.z * M[0][2];
        ret.y = v.x * M[1][0] + v.y * M[1][1] + v.z * M[1][2];
        ret.z = v.x * M[2][0] + v.y * M[2][1] + v.z * M[2][2];

        return ret;
    }

    template<typename T>
    ostream & operator<<(ostream & o, const vect3<T> & v)
    {
        o << v.x << "," << v.y << "," << v.z;

        return o;
    }
}

#endif
