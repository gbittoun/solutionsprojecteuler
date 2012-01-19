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

class HandSet
{
    public :

    enum Figure {HighCard = 0, Pair = 1, TwoPair = 2, ThreeOfAKind = 3, Straight = 4, Flush = 5, FullHouse = 6, FourOfAKind = 7, StraightFlush = 8};

    private:

    Figure f;
    map<int, set<Card::Value> > valueInFigure;
    map<int, set<Card::Value> > otherCards;

    public:

    HandSet(Figure _f, map<int, set<Card::Value> > _vif, map<int, set<Card::Value> > _oc) :
        f(_f),
        valueInFigure(_vif),
        otherCards(_oc)
    {
    }
};

class Hand
{
    set<Card, CardComparer> cards;

    map<Card::Suit, set<Card::Value> > cardsBySuit;
    map<Card::Value, set<Card::Suit> > cardsByValue;

    public:

    void PushCard(Card c)
    {
        cards.insert(c);
        cardsBySuit[c.GetSuit()].insert(c.GetValue());
        cardsByValue[c.GetValue()].insert(c.GetSuit());
    }

    inline bool CheckFor23Full4(HandSet & hs) const
    {
        set<Card::Value> otherValues;

        int pairs = 0;
        set<Card::Value> pairValues;

        bool isThreeOfAKind = false;
        Card::Value threeValue;

        bool isFourOfAKind = false;
        Card::Value fourValue;

        for(map<Card::Value, set<Card::Suit> >::const_iterator it = cardsByValue.begin() ; it != cardsByValue.end() ; ++it)
        {
            if(it->second.size() == 2)
            {
                ++pairs;
                pairValues.insert(it->first);
            }
            else if(it->second.size() == 3)
            {
                isThreeOfAKind = true;
                threeValue = it->first;
            }
            else if(it->second.size() == 4)
            {
                isFourOfAKind = true;
                fourValue = it->first;
            }
            else
                otherValues.insert(it->first);
        }

        HandSet::Figure f = HandSet::HighCard;
        map<int, set<Card::Value> > valueInFigure;
        map<int, set<Card::Value> > otherCards;

        if(isFourOfAKind)
        {
            f = HandSet::FourOfAKind;
            valueInFigure[0].insert(fourValue);
            otherCards[0] = otherValues;
        }
        else if(isThreeOfAKind && pairs == 1)
        {
            f = HandSet::FullHouse;
            valueInFigure[0].insert(threeValue);
            valueInFigure[1] = pairValues;
            otherCards[0] = otherValues;
        }
        else if(isThreeOfAKind)
        {
            f = HandSet::ThreeOfAKind;
            valueInFigure[0].insert(threeValue);
            otherCards[0] = otherValues;
        }
        else if(pairs == 2)
        {
            f = HandSet::TwoPair;
            valueInFigure[0].insert(*pairValues.rbegin());
            valueInFigure[1].insert(*pairValues.begin());
            otherCards[0] = otherValues;
        }
        else if(pairs == 1)
        {
            f = HandSet::Pair;
            valueInFigure[0] = pairValues;
            otherCards[0] = otherValues;
        }
        else
            return false;

        hs = HandSet(f, valueInFigure, otherCards);
        return true;
    }

    inline bool CheckForFlushStraight(HandSet & hs) const
    {
        bool isFlush = false;
        isFlush = (cardsBySuit.size() == 1);

        bool isStraight = false;
        set<Card::Value> values;

        map<Card::Value, set<Card::Suit> >::const_iterator it = cardsByValue.begin();
        values.insert(it->first);
        isStraight &= ((- it->first + (++it)->first) == 1);
        values.insert(it->first);
        isStraight &= ((- it->first + (++it)->first) == 1);
        values.insert(it->first);
        isStraight &= ((- it->first + (++it)->first) == 1);
        values.insert(it->first);
        isStraight &= ((- it->first + (++it)->first) == 1);
        values.insert(it->first);

        HandSet::Figure f = HandSet::HighCard;
        map<int, set<Card::Value> > valueInFigure;
        map<int, set<Card::Value> > otherCards;

        if(isFlush && isStraight)
        {
            f = HandSet::StraightFlush;
            valueInFigure[0] = values;
        }
        else if(isFlush)
        {
            f = HandSet::Flush;
            valueInFigure[0] = values;
        }
        else if(isStraight)
        {
            f = HandSet::Straight;
            valueInFigure[0] = values;
        }
        else
            return false;

        hs = HandSet(f, valueInFigure, otherCards);
        return true;
    }

    inline HandSet GetFigure() const
    {
        HandSet ret(HandSet::HighCard, map<int, set<Card::Value> >(), map<int, set<Card::Value> >() );

        if(CheckFor23Full4(ret))
            return ret;
        else if(CheckForFlushStraight(ret))
            return ret;
        else
        {
            map<int, set<Card::Value> > highCardsValue;
            for(map<Card::Value, set<Card::Suit> >::const_iterator it = cardsByValue.begin() ; it != cardsByValue.end() ; ++it)
                highCardsValue[0].insert(it->first);

            ret = HandSet(HandSet::HighCard, highCardsValue, map<int, set<Card::Value> >() );
            return ret;
        }
    }
};

int main()
{
    return 0;
}
