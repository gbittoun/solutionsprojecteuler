#include "problem_20.hpp"
#include "problem_29.hpp"

#include <set>

using namespace std;
using namespace Computing;

int problem_29()
{
    set<FatNumber<1024>, FatNumber<1024>::CompareFatNumber > numbers;

    for(int idx = 2, jdx = 2 ; (idx <= 100) || ((idx = 2) && (++jdx <= 100)) ; ++idx)
    {
        FatNumber<1024> res = power<1024>(idx, jdx);

        if(numbers.find(res) == numbers.end())
            numbers.insert(res);
    }

    set<FatNumber<1024>, FatNumber<1024>::CompareFatNumber >::iterator it = numbers.begin();
    for(; it != numbers.end() ; ++it)
        cout << *it << endl;

    cout << endl << numbers.size() << endl;

    return 0;
}
