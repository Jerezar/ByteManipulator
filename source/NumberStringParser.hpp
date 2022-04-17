#ifndef NUMBERSTRINGPARSER
#define NUMBERSTRINGPARSER

#include <string>

#include <memory>

class NumberStringParser{
    public:
        virtual int getValueFromString(std::string string_rep) = 0;
}

using ValueParser = std::shared_ptr<NumberStringParser>;
#endif
