#include <iostream>
#include <map>
#include <set>

class Frac
{
    int n, d;
public:

    Frac(int _n, int _d) :
        n(_n),
        d(_d)
    {
    }

    Frac(int _n) :
        n(_n),
        d(1)
    {
    }

    Frac operator+(const Frac & other)
    {
        return Frac(n * other.d + other.n * d, d * other.d);
    }

    Frac operator-(const Frac & other)
    {
        return Frac(n * other.d - other.n * d, d * other.d);
    }

    Frac operator*(const Frac & other)
    {
        return Frac(n * other.n, d * other.d);
    }

    Frac operator/(const Frac & other)
    {
        return Frac(n * other.d, d * other.n);
    }

    bool isValid()
    {
        return d != 0 && n / d * d == n;
    }

    int getNaiveReduced()
    {
        return n / d;
    }
};

typedef Frac (*binary_operator)(Frac, Frac);

Frac binary_plus(Frac x, Frac y)
{
    return x + y;
}

Frac binary_minus(Frac x, Frac y)
{
    return x - y;
}

Frac binary_mult(Frac x, Frac y)
{
    return x * y;
}

Frac binary_divide(Frac x, Frac y)
{
    return x / y;
}

int main()
{
    binary_operator ops[] = {binary_plus, binary_minus, binary_mult, binary_divide};

    std::map<std::set<int>, std::set<int>> results;

    for (int i = 1 ; i < 10 ; ++i)
        for (int j = 1 ; j < 10 ; ++j)
            for (int k = 1 ; k < 10 ; ++k)
                for (int l = 1 ; l < 10 ; ++l)
                {
                    if (i == j || i == k || i == l || j == k || j == l || k == l)
                        continue;

                    for (int oi = 0 ; oi < 4 ; ++oi)
                        for (int oj = 0 ; oj < 4 ; ++oj)
                            for (int ok = 0 ; ok < 4 ; ++ok)
                            {
                                    std::set<int> key;
                                    key.insert(i);
                                    key.insert(j);
                                    key.insert(k);
                                    key.insert(l);

                                    Frac fi(i), fj(j), fk(k), fl(l);

                                        Frac result = ops[ok](ops[oj](ops[oi](fi, fj), fk), fl);
                                        if (result.isValid() && result.getNaiveReduced() > 0)
                                            results[key].insert(result.getNaiveReduced());

                                        result = ops[ok](ops[oj](fi, ops[oi](fj, fk)), fl);
                                        if (result.isValid() && result.getNaiveReduced() > 0)
                                            results[key].insert(result.getNaiveReduced());

                                        result = ops[ok](ops[oj](fi, fj), ops[oi](fk, fl));
                                        if (result.isValid() && result.getNaiveReduced() > 0)
                                            results[key].insert(result.getNaiveReduced());

                                        result = ops[ok](fi, ops[oj](ops[oi](fj, fk), fl));
                                        if (result.isValid() && result.getNaiveReduced() > 0)
                                            results[key].insert(result.getNaiveReduced());

                                        result = ops[ok](fi, ops[oj](fj, ops[oi](fk, fl)));
                                        if (result.isValid() && result.getNaiveReduced() > 0)
                                            results[key].insert(result.getNaiveReduced());
                            }
                }


    // Taking a dump
    // for (auto result : results)
    // {
    //     for (auto key_part : result.first)
    //     {
    //         std::cout << key_part;
    //     }
    //     std::cout << ": ";

    //     for (auto value_part : result.second)
    //     {
    //         std::cout << value_part << ", ";
    //     }
    //     std::cout << std::endl;
    // }

    std::map<std::set<int>, int> counts;

    for (auto result : results)
    {
        int checker = 0;

        for (auto value_part : result.second)
        {
            if (++checker != value_part)
                break;
        }

        counts[result.first] = checker - 1;
    }

    for (auto count_result : counts)
    {
        for (auto key_part : count_result.first)
            std::cout << key_part;
        std::cout << ", " << count_result.second << std::endl;
    }

    return 0;
}