#include "Card.hpp"

namespace Poker
{
    Card::Card() :
        s(Card::Heart),
        v(Card::Queen)
    {
    }

    Card::Card(Suit _s, Value _v) :
        s(_s),
        v(_v)
    {
    }

    Card::Suit Card::GetSuit() const
    {
        return s;
    }

    Card::Value Card::GetValue() const
    {
        return v;
    }
}
