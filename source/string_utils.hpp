#ifndef BYTEMANIPULATOR_STRINGUTILS_HPP
#define BYTEMANIPULATOR_STRINGUTILS_HPP

#include <vector>
#include <string>
namespace fw_byte_manip{
    namespace string_utils{
        std::vector< std::string > split(std::string input, std::string delim);
        /*std::string iso_8859_1_escape(uint8_t value);*/
        std::string ansi_8b_col_text(std::string text, uint8_t value);
        std::string ansi_8b_col_bg(std::string text, uint8_t value);
    }
}
#endif
