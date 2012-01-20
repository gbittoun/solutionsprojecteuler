namespace Poker
{
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

        Card(Suit _s, Value _v);
        Suit GetSuit() const;
        Value GetValue() const;
    };
}
