#ifndef BYTEMANIPULATOR_BRACKETPARSER_HPP
#define BYTEMANIPULATOR_BRACKETPARSER_HPP

#include "InputPreprocessor.hpp"
#include <map>

namespace fw_byte_manip{
    class BracketParser: public InputPreprocessor{
        private:
            static const std::map<char, char> brackets;
        public:
           BracketParser(){};
           std::vector< std::string > parse( std::string input ) override;
    };
}

#endif
