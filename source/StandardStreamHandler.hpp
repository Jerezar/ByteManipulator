#ifndef STANDARDSTREAMHANDLER_HPP
#define STANDARDSTREAMHANDLER_HPP

#include "InputOutputFacility.hpp"

class StandardStreamHandler: public InputOutputFacility{
    public:
        StandardStreamHandler();
        virtual std::string read(std::string prompt) override;
        virtual void print(std::string output) override;
};

#endif
