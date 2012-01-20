#include <iostream>
#include <fstream>
#include <set>
#include <map>

using namespace std;

#include "../PokerGame/PokerConfig.hpp"
#include "problem_54.hpp"

using namespace Poker;

int problem_54()
{
    fstream f("poker.txt");
    string str;

    long long sum = 0;

    while(!f.eof())
    {
        getline(f, str);
        if(str.size() > 5)
        {
            cout << str.substr(0, str.size() - 1) << " : ";

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

            int win = set0.Compare(set1);
            cout << set0.GetFigure() << "," << set1.GetFigure() << " => " << win << endl;

            if(win == 1)
                ++sum;
        }
    }

    cout << endl << "Player 1 wins " << sum <<" hands" << endl;

    return 0;
}
