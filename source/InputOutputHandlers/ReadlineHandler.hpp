#ifndef READLINEHANDLER_HPP
#define READLINEHANDLER_HPP

#include "InputOutputFacility.hpp"

namespace fw_byte_manip{

    /**
    * Reads a file line by line.
    */
    class ReadlineHandler: public InputOutputFacility{
        public:
            ReadlineHandler(){};
            ~ReadlineHandler();
            virtual std::string read(std::string prompt) override;
            virtual void print(std::string output) override;
    };
}

#endif
