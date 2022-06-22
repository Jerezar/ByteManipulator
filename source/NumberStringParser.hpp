#ifndef NUMBERSTRINGPARSER
#define NUMBERSTRINGPARSER

#include <string>

#include <memory>

/**
* An object meant to convert a string into an integer value
*/
class NumberStringParser{
    public:
        /**
        * Converts the string into an integer value
        */
        virtual uint64_t getUnsignedInt(std::string string_rep) = 0;
        /**
        * @returns true If the string can be converted into a number by the object
        */
        virtual bool isUnsignedInt(std::string string_rep) = 0;
};

using ValueParser = std::shared_ptr<NumberStringParser>;
#endif
