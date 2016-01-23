#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>


std::map<std::string, int> getBoardFromVector(std::array<std::string, 40> const & v)
{
    std::map<std::string, int> result;

    for (int i = 0 ; i < v.size() ; ++i)
        result[v[i]] = i;

    return result;
}

std::array<std::string, 40> const nameByPosition = {
    "GO"  , "A1", "CC1", "A2" , "T1", "R1", "B1" , "CH1", "B2", "B3",
    "JAIL", "C1", "U1" , "C2" , "C3", "R2", "D1" , "CC2", "D2", "D3",
    "FP"  , "E1", "CH2", "E2" , "E3", "R3", "F1" , "F2" , "U2", "F3",
    "G2J" , "G1", "G2" , "CC3", "G3", "R4", "CH3", "H1" , "T2", "H2",
};
std::map<std::string, int> const positionByName(getBoardFromVector(nameByPosition));

std::map<std::string, float> resolveSquare(std::string name)
{
    std::map<std::string, float> result;

    if (std::memcmp(name.c_str(), "CC", 2) == 0)
    {
        result["GO"] = 1.0 / 16.0;
        result["JAIL"] = 1.0 / 16.0;

        // Do nothing
        result[name] = 14.0 / 16.0;
    }
    else if (std::memcmp(name.c_str(), "CH", 2) == 0)
    {
        result["GO"] = 1.0 / 16.0;
        result["JAIL"] = 1.0 / 16.0;
        result["C1"] = 1.0 / 16.0;
        result["E3"] = 1.0 / 16.0;
        result["H2"] = 1.0 / 16.0;
        result["R1"] = 1.0 / 16.0;

        int current;

        // Go to next railway company
        current = positionByName.find(name)->second;
        while (nameByPosition[current].c_str()[0] != 'R')
            current = ++current % nameByPosition.size();
        result[nameByPosition[current]] += 2.0 / 16.0;

        // Go to next utility
        current = positionByName.find(name)->second;
        while (nameByPosition[current].c_str()[0] != 'U')
            current = ++current % nameByPosition.size();
        result[nameByPosition[current]] += 1.0 / 16.0;

        // Go back 3 squares
        current = positionByName.find(name)->second;
        current = (current - 3) % nameByPosition.size();
        result[nameByPosition[current]] += 1.0 / 16.0;

        // Do nothing
        result[name] += 6.0 / 16.0;
    }
    else if (std::memcmp(name.c_str(), "G2J", 3) == 0)
    {
        result["JAIL"] = 1.0;
    }
    else
    {
        result[name] = 1.0;
    }

    return result;
}

struct SquareKey
{
    const int doubleDice;
    const std::string name;

    SquareKey(int doubleDice, std::string name) :
        doubleDice(doubleDice),
        name(name)
    {
    }

    bool operator<(SquareKey const & other) const
    {
        if (this->doubleDice != other.doubleDice)
            return this->doubleDice < other.doubleDice;

        return this->name < other.name;
    }

    operator int() const
    {
        return nameByPosition.size() * doubleDice + positionByName.find(name)->second;
    }
};

std::ostream & operator<<(std::ostream & os, SquareKey const & key)
{
    os << "{" << key.doubleDice << ", " << key.name << "}";
}

std::map<SquareKey, float> rollDice(SquareKey squareKey, int diceSize)
{
    std::map<SquareKey, float> result;
    float singleRatio = 1.0 / (diceSize * diceSize);

    for (int i = 1 ; i <= diceSize ; ++i)
    {
        for (int j = 1 ; j <= diceSize ; ++j)
        {
            if (i == j && squareKey.doubleDice == 2)
            {
                result[SquareKey(0, "JAIL")] += singleRatio;
            }
            else
            {
                int doubleDice = (i == j ? squareKey.doubleDice + 1 : 0);
                int current = positionByName.find(squareKey.name)->second;
                std::map<std::string, float> probabilities = resolveSquare(nameByPosition[(current + i + j) % nameByPosition.size()]);

                for (auto probability : probabilities)
                {
                    result[SquareKey(doubleDice, probability.first)] += singleRatio * probability.second;
                }
            }
        }
    }

    return result;
}

int main()
{
    std::cout << "M = [";
    for (int doubleDice = 0 ; doubleDice < 3 ; ++doubleDice)
    {
        for (auto name : nameByPosition)
        {
            std::map<SquareKey, float> results = rollDice(SquareKey(doubleDice, name), 4);

            // float total = 0.0;
            // for (auto result : results)
            // {
            //     total += result.second;
            // }

            // if (total != 1.0)
            //     std::cout << name << " total: " << total <<std::endl;

            std::array<float, 40 * 3> vec;
            for (auto & value : vec)
                value = 0;

            for (auto result : results)
            {
                vec[result.first] = result.second;
            }

            for (auto value : vec)
                std::cout << value << ", ";
            std::cout << ";" << std::endl;
        }
    }

    std::cout << "];" << std::endl;

    std::cout << "M = M';";

    return 0;
}
