#include <iostream>


template<int R, int C>
void computeSolutions(int table[R][C], int r, int c, int colors, long long & count)
{
    if (r == R)
    {
        // for (int r = 0 ; r < R ; ++r)
        // {
        //     for (int c = 0 ; c < C ; ++c)
        //     {
        //         std::cout << table[r][c] << ", ";
        //     }
        //     std::cout << std::endl;
        // }
        // std::cout << std::endl;

        count += 1;
        return;
    }

    for (int i = 0 ; i < colors ; ++i)
    {
        if (r > 0 && table[r - 1][c] == i)
            continue;

        if (c > 0 && table[r][c - 1] == i)
            continue;

        table[r][c] = i;

        if (c == C - 1)
        {
            computeSolutions<R, C>(table, r + 1, 0, colors, count);
        }
        else
        {
            computeSolutions<R, C>(table, r, c + 1, colors, count);
        }
    }
}

int main()
{
    long long count = 0;

    {
        int table[2][2];
        computeSolutions<2, 2>(table, 0, 0, 6, count);
        std::cout << "Count : " << count << std::endl;
    }

    {
        int table[2][3];
        computeSolutions<2, 3>(table, 0, 0, 6, count);
        std::cout << "Count : " << count << std::endl;
    }

    {
        int table[2][4];
        computeSolutions<2, 4>(table, 0, 0, 6, count);
        std::cout << "Count : " << count << std::endl;
    }

    {
        int table[3][2];
        computeSolutions<3, 2>(table, 0, 0, 6, count);
        std::cout << "Count : " << count << std::endl;
    }

    {
        int table[3][3];
        computeSolutions<3, 3>(table, 0, 0, 6, count);
        std::cout << "Count : " << count << std::endl;
    }

    {
        int table[3][4];
        computeSolutions<3, 4>(table, 0, 0, 6, count);
        std::cout << "Count : " << count << std::endl;
    }

    return 0;
}
