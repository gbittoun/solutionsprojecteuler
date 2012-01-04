#include "problem_23.hpp"

#include <iostream>

namespace Computing
{
    set<int> GetDivisors(int N)
    {
        set<int> div;

        if(N <= 0)
            return div;

        div.insert(1);

        for(int idx = N/2 ; idx > 1 ; --idx)
        {
            if(N % idx == 0)
            {
                if(div.find(idx) != div.end())
                    return div;

                div.insert(idx);
                div.insert(N / idx);
            }
        }

        return div;
    }

    int problem_23()
    {
        set<int> abundants;

        for(int idx = 2 ; idx <= 28123 ; ++idx)
        {
            if(GetSum<int>(GetDivisors(idx)) > idx)
                abundants.insert(idx);
        }

        cout << "step 1 done !" << endl;
        cout << "abundants size = " << abundants.size() << endl;

        long long sum = 0;

        for(int idx = 1 ; idx < 28123 ; ++idx)
        {
            set<int>::iterator it = abundants.begin();
            set<int>::iterator bound = abundants.lower_bound(idx);

            bool isCorrect = false;

            while(it != bound)
            {
                if(abundants.find(idx - *it) != abundants.end())
                {
                    isCorrect = true;
                    break;
                }
                ++it;
            }

            if(!isCorrect)
            {
                sum += idx;
            }
        }

        cout << sum << endl;

        return 0;
    }
}
