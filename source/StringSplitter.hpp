#ifndef BYTEMANIPULATOR_STRINGSPLITTER_HPP
#define BYTEMANIPULATOR_STRINGSPLITTER_HPP

#include "InputPreprocessor.hpp"

namespace fw_byte_manip{
   class StringSplitter: public InputPreprocessor{
       public:
           StringSplitter(){};
           std::vector< std::string > parse( std::string input ) override;
   };
}

#endif
