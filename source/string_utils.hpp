#ifndef BYTEMANIPULATOR_STRINGUTILS_HPP
#define BYTEMANIPULATOR_STRINGUTILS_HPP

#include <vector>
#include <string>
namespace fw_byte_manip{
    namespace string_utils{
        /**
        * Splits a string along a pattern, returning the fragments as a list.
        * @param input The string that is getting split
        * @param delim The pattern of the breakpoints.
        */
        std::vector< std::string > split(std::string input, std::string delim);
        /**
        * @returns An integer containing the utf-8 encoding of a unicode character.
        *@note The returned integer will most often not be a proper utf-8 character itself; as it will always be 4 bytes even when the actual utf-8 encoding would take less. In order to convert it to an actual utf-8 string pass it to utf8_string_from_int32(int c)
        *@param c The codepoint of the desired unicode character.
        */
        int codepoint_to_utf8( uint32_t c );
        
        /**
        *Takes an utf-8 encoding and writes it into a string.
        *@param c An integer containing the utf-8 encoding of a unicode character.
        *@returns A string with the actual unicode character.
        */
        std::string utf8_string_from_int32(int c);
        
        /**
        * Surrounds a string with the ANSI escape sequence for colored text.
        */
        std::string ansi_8b_col_text(std::string text, uint8_t value);
        
        /**
        * Surrounds a string with the ANSI escape sequence for a colored background.
        */
        std::string ansi_8b_col_bg(std::string text, uint8_t value);
    }
}
#endif
