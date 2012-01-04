#include <utility>

namespace Computing
{
    using namespace std;

    class ComparePair
    {
        public :

        bool operator()(const pair<int, int> & a, const pair<int, int> & b);
    };
}

int problem_26();
