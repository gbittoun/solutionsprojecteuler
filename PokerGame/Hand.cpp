#include <set>
#include <map>

using namespace std;

#include "Card.hpp"
#include "HandSet.hpp"
#include "Hand.hpp"

namespace Poker
{
    inline bool Hand::CheckFor23Full4(HandSet & hs) const
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

    inline bool Hand::CheckForFlushStraight(HandSet & hs) const
    {
        bool isFlush = false;
        isFlush = (cardsBySuit.size() == 1);

        bool isStraight = true;
        set<Card::Value> values;

        map<Card::Value, set<Card::Suit> >::const_iterator it0 = cardsByValue.begin();
        map<Card::Value, set<Card::Suit> >::const_iterator it1 = it0;
        ++it1;

        for(int idx = 0 ; idx < 4 ; ++idx)
        {
            if(it1->first - it0->first != 1)
                isStraight = false;

            ++it0;
            ++it1;
        }

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

    void Hand::PushCard(Card c)
    {
        cardsBySuit[c.GetSuit()].insert(c.GetValue());
        cardsByValue[c.GetValue()].insert(c.GetSuit());
    }

    HandSet Hand::GetHandSet() const
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
}
