

template<int n>
Computing::FatNumber<n> power(const int & a, const int & b)
{
    Computing::FatNumber<n> ret;
    ret = 1;

    for(int idx = 0 ; idx < b ; ++idx)
    {
        ret = ret * a;
    }

    return ret;
}

int problem_29();
