#include "problems/problem_2.hpp"
#include "problems/problem_3.hpp"
#include "problems/problem_4.hpp"
#include "problems/problem_7.hpp"
#include "problems/problem_9.hpp"
#include "problems/problem_10.hpp"
#include "problems/problem_11.hpp"
#include "problems/problem_12.hpp"
#include "problems/problem_13.hpp"
#include "problems/problem_14.hpp"
#include "problems/problem_15.hpp"
#include "problems/problem_16.hpp"
#include "problems/problem_17.hpp"
#include "problems/problem_18.hpp"
#include "problems/problem_19.hpp"
#include "problems/problem_20.hpp"
#include "problems/problem_21.hpp"
#include "problems/problem_22.hpp"
#include "problems/problem_23.hpp"
#include "problems/problem_24.hpp"
#include "problems/problem_25.hpp"
#include "problems/problem_26.hpp"
#include "problems/problem_27.hpp"
#include "problems/problem_28.hpp"
#include "problems/problem_29.hpp"
#include "problems/problem_30.hpp"
#include "problems/problem_31.hpp"
#include "problems/problem_32.hpp"
#include "problems/problem_33.hpp"
#include "problems/problem_34.hpp"
#include "problems/problem_35.hpp"
#include "problems/problem_36.hpp"
#include "problems/problem_37.hpp"
#include "problems/problem_38.hpp"
#include "problems/problem_40.hpp"
#include "problems/problem_41.hpp"
#include "problems/problem_42.hpp"
#include "problems/problem_43.hpp"
#include "problems/problem_44.hpp"
#include "problems/problem_45.hpp"
#include "problems/problem_46.hpp"
#include "problems/problem_47.hpp"
#include "problems/problem_48.hpp"
#include "problems/problem_49.hpp"
#include "problems/problem_50.hpp"
#include "problems/problem_51.hpp"
#include "problems/problem_52.hpp"

using namespace std;
using namespace Computing;

#include <vector>

class Card
{
    public:

    // There is no meaning to Suit value, it's just useful to order them in a set
    enum Suit {Spade = 0, Heart = 1, Diamond = 2, Club = 3};
    enum Value {Two = 2, Three = 3, Four = 4, Five = 5, Six = 6, Seven = 7, Eight = 8, Nine = 9, Ten = 10, Jack = 11, Queen = 12, King = 13, Ace = 14};

    private:

    Suit s;
    Value v;

    public:

    Card(Suit _s, Value _v) :
        s(_s),
        v(_v)
    {
    }

    Suit GetSuit() const
    {
        return s;
    }

    Value GetValue() const
    {
        return v;
    }
};

struct CardComparer
{
    bool operator()(const Card & c0, const Card & c1)
    {
        if(c0.GetValue() < c1.GetValue())
            return true;
        else if(c0.GetValue() > c1.GetValue())
            return false;
        else if(c0.GetSuit() < c1.GetSuit())
            return true;
        else if(c0.GetSuit() > c1.GetSuit())
            return false;

        return false;
    }
};

class Hand
{
    set<Card, CardComparer> cards;

    map<Card::Suit, vector<Card::Value> > cardsBySuit;
    map<Card::Value, vector<Card::Suit> > cardsByValue;

    public:

    enum Figure {HighCard = 0, Pair = 1, TwoPair = 2, ThreeOfAKind = 3, Straight = 4, Flush = 5, FullHouse = 6, FourOfAKind = 7, StraightFlush = 8};

    void PushCard(Card c)
    {
        cards.insert(c);
        cardsBySuit[c.GetSuit()].push_back(c.GetValue());
        cardsByValue[c.GetValue()].push_back(c.GetSuit());
    }

    Figure GetFigure()
    {
        for(map<Card::Value, vector<Card::Suit> >::iterator it = cardsByValue.begin() ; it != cardsByValue.end() ; ++it)
        {
        }

        return Pair;
    }
};

int main()
{
    return 0;
}
