#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>


bool hasFactor(long long n, std::set<long long> & s)
{
    for (auto num : s)
    {
        if (num > std::sqrt(n))
            break;

        if (n % num == 0)
            return false;
    }

    return true;
}

std::set<long long> getPrimes(long long nMax)
{
    std::set<long long> result;

    for (long long i = 2 ; i < nMax ; ++i)
        if (hasFactor(i, result))
            result.insert(i);

    return result;
}

std::set<long long> const primes = getPrimes(1000000);

std::map<int, int> reduce(std::vector< std::map<int, std::set<int>>> memory)
{
    std::map<int, int> result;

    for (auto item : memory)
    {
        for (auto it : item)
        {
            result[it.first] = std::accumulate(it.second.begin(), it.second.end(), 0);
        }
    }

    return result;
}

std::map<int, int> getDivisorsMap()
{
    std::vector< std::map<int, std::set<int>>> memory;

    {
        std::map<int, std::set<int>> first;
        for (auto prime : primes)
        {
            first[prime].insert(1);
        }
        memory.push_back(first);
    }

    while (true)
    {
        std::map<int, std::set<int>> next;

        for (auto it : *memory.rbegin())
        {
            for (auto prime : primes)
            {
                if (it.first * prime < 1000000)
                {
                    for (auto divisor : it.second)
                        next[it.first * prime].insert(divisor * prime);

                    next[it.first * prime].insert(it.second.begin(), it.second.end());
                }
                else
                    break;
            }
        }

        if (next.size() == 0)
            break;

        memory.push_back(next);
    }

    std::cout << "Step 1 done" << std::endl;
    std::map<int, int> final = reduce(memory);
    std::cout << "Step 2 done" << std::endl;

    return final;
}

int main()
{
    std::map<int, int> final = getDivisorsMap();

    for (auto item : final)
    {
        std::set<int> container;
        std::vector<int> chain;

        container.insert(item.first);
        chain.push_back(item.first);

        int next = item.second;
        while (final.find(next) != final.end() && container.find(next) == container.end())
        {
            container.insert(next);
            chain.push_back(next);

            next = final[next];
        }

        if (next == *chain.begin())
        {
            for (auto it : chain)
                std::cout << it << " -> ";
            std::cout << std::endl;
        }
    }

    return 0;
}