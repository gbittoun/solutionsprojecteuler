namespace Poker
{
    class HandParser
    {
        public :

        enum ParseStatus {Error = 0, Success = 1};

        private :

        string description;
        string::const_iterator it;

        ParseStatus errorFlag;

        public :

        HandParser(string description);
        ParseStatus PopCard(Card & c);
    };
}
