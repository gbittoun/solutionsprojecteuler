#include <map>
#include <set>

namespace Poker
{
    class Hand
    {
        std::map<Card::Suit, std::set<Card::Value> > cardsBySuit;
        std::map<Card::Value, std::set<Card::Suit> > cardsByValue;

        inline bool CheckFor23Full4(HandSet & hs) const;
        inline bool CheckForFlushStraight(HandSet & hs) const;

        public:

        void PushCard(Card c);
        HandSet GetHandSet() const;
    };
}
