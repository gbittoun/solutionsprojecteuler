#include <iostream>
#include <fstream>
#include <math.h>

#include "problem_99.hpp"

long long ReadLongLong(const char * & str)
{
    long long result = 0;

    while ((*str >= 48) && (*str <= 57))
    {
        result = result * 10 + (*str - 48);
        ++str;
    }

    return result;
}

int problem_99()
{
    std::ifstream infile("base_exp.txt");
    std::string line;

    double max = 0;

    int n = 0;

    while(!infile.eof())
    {
        long long a, b;

        std::getline(infile, line);
        ++n;
        const char * str = line.c_str();

        a = ReadLongLong(str);
        ++str;
        b = ReadLongLong(str);

        if (b * log(a) > max)
        {
            std::cout << n << " => " << a << "^" << b << std::endl;
            max = b * log(a);
        }
    }
}
