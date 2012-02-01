#include "Computing/IntegerOperations.hpp"

using namespace std;
using namespace Computing;

int main()
{
    long long D = 15;
    vector<long long> c;

    GetSqrtCoeff(D, c);
    FatFraction<64> fract = DevelopSqrtCoeff<64>(c, 1);

    cout << fract.u << " / " << fract.d << endl;

    return 0;
}
