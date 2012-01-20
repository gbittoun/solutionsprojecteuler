namespace Poker
{
    class HandSet
    {
        public :

        enum Figure {HighCard = 0, Pair = 1, TwoPair = 2, ThreeOfAKind = 3, Straight = 4, Flush = 5, FullHouse = 6, FourOfAKind = 7, StraightFlush = 8};

        private:

        Figure f;
        map<int, set<Card::Value> > valueInFigure;
        map<int, set<Card::Value> > otherCards;

        public:

        HandSet(Figure _f, map<int, set<Card::Value> > _vif, map<int, set<Card::Value> > _oc);
        Figure GetFigure() const;
        int Compare(const HandSet & hs) const;
    };
}
