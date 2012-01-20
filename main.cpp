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

#include "PokerGame/PokerConfig.hpp"

using namespace Poker;

class HandParser
{
    public :

    enum ParseStatus {Error = 0, Success = 1};

    private :

    string description;
    string::const_iterator it;

    ParseStatus errorFlag;

    public :

    HandParser(string description) :
        description(description),
        it(),
        errorFlag(Success)
    {
        it = description.begin();
    }

    ParseStatus PopCard(Card & c)
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
};

int main()
{
    string str("8C TS KC 9H 4S 7D 2S 5D 3S AC");
    HandParser parser(str);

    Card c;
    Hand h0, h1;

    for(int idx = 0 ; idx < 5 ; ++idx)
    {
        if(parser.PopCard(c))
            h0.PushCard(c);
        else
            return 1;
    }

    for(int idx = 0 ; idx < 5 ; ++idx)
    {
        if(parser.PopCard(c))
            h1.PushCard(c);
        else
            return 1;
    }

    HandSet set0 = h0.GetHandSet();
    HandSet set1 = h1.GetHandSet();

    cout << set0.GetFigure() << "," << set1.GetFigure() << endl;
    cout << set0.Compare(set1) << endl;

    return 0;
}
