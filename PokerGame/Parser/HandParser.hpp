#include <string>

namespace Poker
{
    class HandParser
    {
        public :

        enum ParseStatus {Error = 0, Success = 1};

        private :

        std::string description;
        std::string::const_iterator it;

        ParseStatus errorFlag;

        public :

        HandParser(std::string description);
        ParseStatus PopCard(Card & c);
    };
}
