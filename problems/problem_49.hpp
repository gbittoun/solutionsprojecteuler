#include <map>

namespace Computing
{
    using namespace std;

    template<int DIGITS, int BASE>
    void DigitsDecompose(long long n, map<char, int> & digits);

    struct DigitsComparer
    {
        bool operator()(const map<char, int> & x, const map<char, int> & y)
        {
            map<char, int>::const_iterator it_x = x.begin();
            map<char, int>::const_iterator it_y = y.begin();

            bool endx = false, endy = false;

            while(true)
            {

                if(it_x == x.end())
                    endx = true;

                if(it_y == y.end())
                    endy = true;

                if(endx || endy)
                    break;

                if(*it_x < *it_y)
                    return true;
                else if(*it_x > *it_y)
                    return false;

                ++it_x;
                ++it_y;
            }

            if(endx && !endy)
                return true;

            return false;
        }
    };
}

int problem_49();
