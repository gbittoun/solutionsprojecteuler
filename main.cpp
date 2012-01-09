#include "problems/problem_2.hpp"
#include "problems/problem_3.hpp"
#include "problems/problem_4.hpp"
#include "problems/problem_7.hpp"
#include "problems/problem_9.hpp"
#include "problems/problem_10.hpp"
#include "problems/problem_11.hpp"
#include "problems/problem_12.hpp"
#include "problems/problem_13.hpp"
#include "problems/problem_14.hpp"
#include "problems/problem_15.hpp"
#include "problems/problem_16.hpp"
#include "problems/problem_17.hpp"
#include "problems/problem_18.hpp"
#include "problems/problem_19.hpp"
#include "problems/problem_20.hpp"
#include "problems/problem_21.hpp"
#include "problems/problem_22.hpp"
#include "problems/problem_23.hpp"
#include "problems/problem_24.hpp"
#include "problems/problem_25.hpp"
#include "problems/problem_26.hpp"
#include "problems/problem_27.hpp"
#include "problems/problem_28.hpp"
#include "problems/problem_29.hpp"
#include "problems/problem_30.hpp"
#include "problems/problem_31.hpp"
#include "problems/problem_32.hpp"
#include "problems/problem_33.hpp"
#include "problems/problem_34.hpp"
#include "problems/problem_35.hpp"
#include "problems/problem_36.hpp"
#include "problems/problem_37.hpp"

using namespace std;
using namespace Computing;

#include <sstream>

int main()
{
    for (long long idx = 1 ; idx < 10000 ; ++idx)
    {
        ostringstream stream;
        long long factor = 1;
        set<int> digits;

        while(true)
        {
            stream << idx * factor;

            for(size_t s = 0 ; s < stream.str().size() ; ++s)
            {
                digits.insert(stream.str().c_str()[s]);
            }

            if(stream.str().size() != digits.size())
                break;
            else if( (digits.find('0') == digits.end()) && (stream.str().size() == digits.size()) && (digits.size() == 9) )
            {
                cout << idx << " " << stream.str() << endl;
                break;
            }

            ++factor;
        }
    }

    return 0;
}
