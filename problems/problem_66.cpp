#include "../Computing/IntegerOperations.hpp"

#include <math.h>

using namespace std;
using namespace Computing;


int main()
{
    FatNumber<64> maxxplus = 0, maxxminus = 0;
    long long finalDplus = 0, finalDminus = 0;

    for(long long D = 2 ; D <= 1000 ; ++D)
    {
        if(floor(sqrt(D)) == ceil(sqrt(D)))
            continue;

        vector<long long> c;

        GetSqrtCoeff(D, c);
        FatFraction<64> fract = DevelopSqrtCoeff<64>(c, 1, true);

        cout << D << " " << fract.u << " / " << fract.d << " => " << fract.u * fract.u - fract.d * fract.d * D << endl;

        if(maxxminus < fract.u && ((fract.u * fract.u) - (fract.d * fract.d * D)) == -1 )
        {
            finalDminus = D;
            maxxminus = fract.u;
        }
        else if (maxxplus < fract.u && ((fract.u * fract.u) - (fract.d * fract.d * D)) == 1 )
        {
            finalDplus = D;
            maxxplus = fract.u;
        }
    }

    cout << endl << finalDminus << " " << maxxminus;
    cout << endl << finalDplus << " " << maxxplus << endl;

    return 0;
}
