#ifndef STANDARDSTREAMHANDLER_HPP
#define STANDARDSTREAMHANDLER_HPP

#include "InputOutputFacility.hpp"

namespace fw_byte_manip{
    /**
    * Reads from, and prints to, the standard streams.
    */
    class StandardStreamHandler: public InputOutputFacility{
        public:
            StandardStreamHandler();
            /**
            * Reads from standard input.
            * @param prompt String printed to standard output.
            */
            virtual std::string read(std::string prompt) override;
            /**
            * Prints to standard output.
            */
            virtual void print(std::string output) override;
    };
}

#endif
