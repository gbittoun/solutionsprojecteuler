#include <array>
#include <iostream>
#include <set>
#include <vector>


std::ostream & operator<<(std::ostream & os, std::set<int> const & dice)
{
    os << "{";
    for (auto num : dice)
        os << num << ",";
    os << "}";

    return os;
}

bool compatible(std::set<int> dice1, std::set<int> dice2)
{
    std::array<int, 9> squares = {1, 4, 6, 16, 25, 36, 46, 64, 81};

    if (dice1.find(9) != dice1.end())
    {
        dice1.erase(9);
        dice1.insert(6);
    }

    if (dice2.find(9) != dice2.end())
    {
        dice2.erase(9);
        dice2.insert(6);
    }

    std::set<int> checkSet(squares.begin(), squares.end());

    for (auto n1 : dice1)
    {
        for (auto n2 : dice2)
        {
            checkSet.erase(n1 + 10 * n2);
            checkSet.erase(n2 + 10 * n1);
        }
    }

    return checkSet.size() == 0;
}

int main()
{
    std::set<std::set<int>> allDice;

    for (int i = 0 ; i < 10 * 9 * 8 * 7 * 6 * 5 ; ++i)
    {
        int k = i;

        std::set<int> dice;
        for (int j = 0 ; j < 6 ; ++j)
        {
            dice.insert(k % 10);
            k /= 10;
        }

        if (dice.size() == 6)
        {
            allDice.insert(dice);
        }
    }

    for (auto dice : allDice)
    {
        std::cout << dice << std::endl;
    }

    std::cout << allDice.size() << std::endl;

    std::set<std::pair<std::set<int>, std::set<int>>> allCompatibleDice;

    for (auto dice1 : allDice)
    {
        for (auto dice2 : allDice)
        {
            if (compatible(dice1, dice2))
            {
                allCompatibleDice.insert(std::make_pair(dice1, dice2));
            }
        }
    }

    for (auto dicePair : allCompatibleDice)
    {
        std::cout << dicePair.first << "; " << dicePair.second << std::endl;
    }

    std::cout << allCompatibleDice.size() / 2 << std::endl;

    return 0;
}
