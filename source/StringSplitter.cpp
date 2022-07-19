#include "StringSplitter.hpp"


#include "string_utils.hpp"

namespace fw_byte_manip{
    std::vector< std::string > StringSplitter::parse( std::string input ){
        return fw_byte_manip::string_utils::split( input, " ");
    }
}
