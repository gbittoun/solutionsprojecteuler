#include "problem_61.hpp"

#include <iostream>
#include <set>

#include "../Computing/IntegerOperations.hpp"
#include "../Computing/Combination.hpp"

using namespace std;
using namespace Computing;

void TestPolygonalSolution(set<int> & s0, set<int> & s1, set<int> & s2, set<int> & s3, set<int> & s4, set<int> & s5)
{
    for(set<int>::iterator it0 = s0.begin() ; it0 != s0.end() ; ++it0)
    {
        for(set<int>::iterator it1 = s1.begin() ; it1 != s1.end() ; ++it1)
        {
            if(*it0 % 100 == *it1 / 100)
            {
                for(set<int>::iterator it2 = s2.begin() ; it2 != s2.end() ; ++it2)
                {
                    if(*it1 % 100 == *it2 / 100)
                    {
                        for(set<int>::iterator it3 = s3.begin() ; it3 != s3.end() ; ++it3)
                        {
                            if(*it2 % 100 == *it3 / 100)
                            {
                                for(set<int>::iterator it4 = s4.begin() ; it4 != s4.end() ; ++it4)
                                {
                                    if(*it3 % 100 == *it4 / 100)
                                    {
                                        for(set<int>::iterator it5 = s5.begin() ; it5 != s5.end() ; ++it5)
                                        {
                                            if( (*it4 % 100 == *it5 / 100) && (*it5 % 100 == *it0 / 100) )
                                            {
                                                cout << *it0 << " " << *it1 << " " << *it2 << " " << *it3 << " " << *it4 << " " << *it5 << " : " <<
                                                *it0 + *it1 + *it2 + *it3 + *it4 + *it5 << endl;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int problem_61()
{
    set<int> s[6];

    for(int n = 0 ; n < 1000 ; ++n)
    {
        int tmp = PolygonalNumber<3, int>(n);
        if(tmp >= 1000 && tmp < 10000)
            s[0].insert(tmp);

        tmp = PolygonalNumber<4, int>(n);
        if(tmp >= 1000 && tmp < 10000)
            s[1].insert(tmp);

        tmp = PolygonalNumber<5, int>(n);
        if(tmp >= 1000 && tmp < 10000)
            s[2].insert(tmp);

        tmp = PolygonalNumber<6, int>(n);
        if(tmp >= 1000 && tmp < 10000)
            s[3].insert(tmp);

        tmp = PolygonalNumber<7, int>(n);
        if(tmp >= 1000 && tmp < 10000)
            s[4].insert(tmp);

        tmp = PolygonalNumber<8, int>(n);
        if(tmp >= 1000 && tmp < 10000)
            s[5].insert(tmp);
    }

    ProbabilisticPyramid<set<int>, 6> p(s);

    for(long long idx = 0 ; idx < Factorial(6) ; ++idx)
    {
        ProbabilisticPyramid<set<int>, 6>::ProbabilisticSolution solution = p.GetCombination(idx);
        TestPolygonalSolution(solution.a[0], solution.a[1], solution.a[2], solution.a[3], solution.a[4], solution.a[5]);
    }

    return 0;
}
