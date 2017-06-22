#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int main()
{
    set<string> results;

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
                results.insert(stream.str());
                break;
            }

            ++factor;
        }
    }

    cout << endl << *results.rbegin() << endl;

    return 0;
}
