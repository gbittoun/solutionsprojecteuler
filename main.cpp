#include "Computing/IntegerOperations.hpp"

#include <math.h>

using namespace std;
using namespace Computing;

int main()
{
    FatNumber<64> maxx = 0;
    long long finalD = 0;

    for(long long D = 2 ; D <= 1000 ; ++D)
    {
        if(floor(sqrt(D)) == ceil(sqrt(D)))
            continue;

        vector<long long> c;

        GetSqrtCoeff(D, c);
        FatFraction<64> fract = DevelopSqrtCoeff<64>(c, 1, true);

        cout << D << " " << fract.u << " / " << fract.d << " => " << fract.u * fract.u - fract.d * fract.d * D << endl;

        if(maxx < fract.u && ((fract.u * fract.u) - (fract.d * fract.d * D)) == -1 )
        {
            finalD = D;
            maxx = fract.u;
        }
    }

    cout << endl << finalD << " " << maxx << endl;

    return 0;
}
