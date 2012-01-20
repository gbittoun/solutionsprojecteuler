#include <string>
#include <set>
#include <map>

using namespace std;

#include "../Card.hpp"
#include "../HandSet.hpp"
#include "../Hand.hpp"
#include "HandParser.hpp"

namespace Poker
{
    HandParser::HandParser(string description) :
        description(description),
        it(),
        errorFlag(Success)
    {
        it = description.begin();
    }

    HandParser::ParseStatus HandParser::PopCard(Card & c)
    {
        if(errorFlag == Error)
            return errorFlag;

        while(it != description.end() && *it <= ' ')
            ++it;

        Card::Value v = Card::Queen;
        Card::Suit s = Card::Heart;

        switch(*it)
        {
            case '2':
                v = Card::Two;
                break;
            case '3':
                v = Card::Three;
                break;
            case '4':
                v = Card::Four;
                break;
            case '5':
                v = Card::Five;
                break;
            case '6':
                v = Card::Six;
                break;
            case '7':
                v = Card::Seven;
                break;
            case '8':
                v = Card::Eight;
                break;
            case '9':
                v = Card::Nine;
                break;
            case 'T':
                v = Card::Ten;
                break;
            case 'J':
                v = Card::Jack;
                break;
            case 'Q':
                v = Card::Queen;
                break;
            case 'K':
                v = Card::King;
                break;
            case 'A':
                v = Card::Ace;
                break;
            default:
                return (errorFlag = Error);
                break;
        }
        ++it;

        switch(*it)
        {
            case 'S':
                s = Card::Spade;
                break;
            case 'H':
                s = Card::Heart;
                break;
            case 'D':
                s = Card::Diamond;
                break;
            case 'C':
                s = Card::Club;
                break;
            default :
                return (errorFlag = Error);
                break;
        }
        ++it;

        c = Card(s, v);
        return (errorFlag = Success);
    }
}
