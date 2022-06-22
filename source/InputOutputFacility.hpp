#ifndef INPUTOUTPUTFACILITY_HPP
#define INPUTOUTPUTFACILITY_HPP

#include <memory>
#include <string>

namespace fw_byte_manip{
    /**
    * Responsible for reading input to the program and putting out responses.
    */
    class InputOutputFacility {
        public:
            /**
            * Reads a line of input.
            * @param prompt A string of output that may be shown to the user.
            */
            virtual std::string read(std::string prompt) = 0;
            /**
            * Puts out a string.
            */
            virtual void print(std::string output) = 0;
    };
    
    using InputOutputHandler = std::shared_ptr<InputOutputFacility>;
}

#endif
