#include <set>
#include <map>

using namespace std;

#include "Card.hpp"

#include "HandSet.hpp"

namespace Poker
{
    HandSet::HandSet(Figure _f, map<int, set<Card::Value> > _vif, map<int, set<Card::Value> > _oc) :
        f(_f),
        valueInFigure(_vif),
        otherCards(_oc)
    {
    }

    HandSet::Figure HandSet::GetFigure() const
    {
        return f;
    }

    int HandSet::Compare(const HandSet & hs) const
    {
        if(f < hs.f)
            return -1;
        else if(f > hs.f)
            return 1;

        Card::Value v0 = *valueInFigure.begin()->second.rbegin();
        Card::Value v1 = *hs.valueInFigure.begin()->second.rbegin();

        if(v0 < v1)
            return -1;
        else if(v0 > v1)
            return 1;

        if(f == FullHouse || f == TwoPair)
        {
            v0 = *(valueInFigure.rbegin()->second.rbegin());
            v1 = *(hs.valueInFigure.rbegin()->second.rbegin());

            if(v0 < v1)
                return -1;
            else if(v0 > v1)
                return 1;
        }
        else if(f == Flush || f == HighCard)
        {
            for(set<Card::Value>::const_reverse_iterator it0 = valueInFigure.begin()->second.rbegin() ,
                                                         it1 = hs.valueInFigure.begin()->second.rbegin() ;
                it0 != valueInFigure.begin()->second.rend() && it1 != hs.valueInFigure.begin()->second.rend() ;
                ++it0, ++it1)
            {
                if(*it0 < *it1)
                    return -1;
                else if(*it0 > *it1)
                    return 1;
            }
        }

        for(set<Card::Value>::const_reverse_iterator it0 = otherCards.begin()->second.rbegin() ,
                                                     it1 = hs.otherCards.begin()->second.rbegin() ;
            it0 != otherCards.begin()->second.rend() && it1 != hs.otherCards.begin()->second.rend() ;
            ++it0, ++it1)
        {
            if(*it0 < *it1)
                return -1;
            else if(*it0 > *it1)
                return 1;
        }

        return 0;
    }
}
