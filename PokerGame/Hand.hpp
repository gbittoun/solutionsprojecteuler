namespace Poker
{
    class Hand
    {
        map<Card::Suit, set<Card::Value> > cardsBySuit;
        map<Card::Value, set<Card::Suit> > cardsByValue;

        inline bool CheckFor23Full4(HandSet & hs) const;
        inline bool CheckForFlushStraight(HandSet & hs) const;

        public:

        void PushCard(Card c);
        HandSet GetHandSet() const;
    };
}
