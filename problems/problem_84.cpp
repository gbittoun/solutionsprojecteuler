#include <functional>
#include <map>
#include <string>
#include <vector>


template<typename T>
class ProbabilityCouple
{
    T const item;
    float const probability;

public:

    ProbabilityCouple(T item, float probability) :
        item(item),
        probability(probability)
    {
    }
};


class BoardSquare
{
    std::string id;
    BoardSquare const * nextSquare;

protected:

    std::map<std::string, BoardSquare const *> const * squaresByName;

public:

    BoardSquare(std::string id, std::map<std::string, BoardSquare const *> const * squaresByName, BoardSquare const * nextSquare = 0) :
        id(id),
        squaresByName(squaresByName),
        nextSquare(nextSquare)
    {
    }

    std::string getId() const
    {
        return this->id;
    }

    BoardSquare const * next() const
    {
        return this->nextSquare;
    }

    void setNextSquare(BoardSquare const * nextSquare)
    {
        this->nextSquare = nextSquare;
    }

    virtual std::vector<ProbabilityCouple<BoardSquare const *>> resolve() const
    {
        std::vector<ProbabilityCouple<BoardSquare const *>> probabilities;
        probabilities.push_back(ProbabilityCouple<BoardSquare const *>(this, 1));

        return probabilities;
    }
};


class CommunityChestBoardSquare : public BoardSquare
{
public:

    virtual std::vector<ProbabilityCouple<BoardSquare const *>> resolve() const
    {
        std::vector<ProbabilityCouple<BoardSquare const *>> probabilities;

        probabilities.push_back(ProbabilityCouple<BoardSquare const *>(this, 14.0/16.0));
        probabilities.push_back(ProbabilityCouple<BoardSquare const *>(squaresByName->find("GO")->second, 1.0/16.0));
        probabilities.push_back(ProbabilityCouple<BoardSquare const *>(squaresByName->find("JAIL")->second, 1.0/16.0));
    }
};


class ChanceBoardSquare : public BoardSquare
{
public:

    virtual std::vector<ProbabilityCouple<BoardSquare const *>> resolve() const
    {
        std::vector<ProbabilityCouple<BoardSquare const *>> probabilities;

        probabilities.push_back(ProbabilityCouple<BoardSquare const *>(this, 6.0/16.0));
        probabilities.push_back(ProbabilityCouple<BoardSquare const *>(squaresByName->find("GO")->second, 1.0/16.0));
        probabilities.push_back(ProbabilityCouple<BoardSquare const *>(squaresByName->find("JAIL")->second, 1.0/16.0));
        probabilities.push_back(ProbabilityCouple<BoardSquare const *>(squaresByName->find("C1")->second, 1.0/16.0));
        probabilities.push_back(ProbabilityCouple<BoardSquare const *>(squaresByName->find("E3")->second, 1.0/16.0));
        probabilities.push_back(ProbabilityCouple<BoardSquare const *>(squaresByName->find("H2")->second, 1.0/16.0));
        probabilities.push_back(ProbabilityCouple<BoardSquare const *>(squaresByName->find("R1")->second, 1.0/16.0));

        // Finding next railway company
        auto next = this->next();
        while(next->getId().c_str()[0] != 'R')
        {
            next = next->next();
        }
        probabilities.push_back(ProbabilityCouple<BoardSquare const *>(next, 2.0/16.0));

        // Finding next utility company
        next = this->next();
        while(next->getId().c_str()[0] != 'U')
        {
            next = next->next();
        }
        probabilities.push_back(ProbabilityCouple<BoardSquare const *>(next, 1.0/16.0));

        BoardSquare const * previous = this;
        next = this->next()->next();

        while (next != this)
        {
            next = next->next();
            previous = previous->next();
        }
        probabilities.push_back(ProbabilityCouple<BoardSquare const *>(previous, 1.0/16.0));
    }
};


class Cursor
{
    int doubleDiceCount;
    BoardSquare const * square;
    std::map<std::string, BoardSquare const *> const * squaresByName;


public:

    Cursor(
        int doubleDiceCount,
        BoardSquare const * square,
        std::map<std::string, BoardSquare const *> const * squaresByName) :
            doubleDiceCount(doubleDiceCount),
            square(square),
            squaresByName(squaresByName)
    {
        if (doubleDiceCount > 2)
            throw "You did something really bad :)";
    }

    bool operator<(Cursor const & other)
    {
        if (this->doubleDiceCount < other.doubleDiceCount)
            return true;
        if (other.doubleDiceCount < this->doubleDiceCount)
            return false;
        return this->square->getId() < other.square->getId();
    }

    std::vector<ProbabilityCouple<Cursor>> rollDice(int diceSize)
    {
        std::vector<ProbabilityCouple<Cursor>> cursors;

        for (int i = 1 ; i <= diceSize ; ++i)
        {
            for (int j = i ; j <= diceSize ; ++j)
            {
                if ((doubleDiceCount == 2) && (i == j))
                {
                    Cursor result(0, squaresByName->find("JAIL")->second, this->squaresByName);
                    cursors.push_back(ProbabilityCouple<Cursor>(result, 1.0/(diceSize * diceSize)));
                }
                else
                {
                    auto target = this->square;

                    for (int k = 0 ; k < i + j ; ++k)
                        target = target->next();

                    auto results = target->resolve();
                }
            }
        }
    }
};

int main()
{
    return 0;
}
