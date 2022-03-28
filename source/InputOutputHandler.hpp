#ifndef INPUTOUTPUTHANDLER_HPP
#define INPUTOUTPUTHANDLER_HPP

#include <memory>
#include <string>

class InputOutputFacility {
    public:
        virtual std::string read(std::string prompt) = 0;
        virtual void print(std::string output) = 0;
};

using InputOutputHandler = std::shared_ptr<InputOutputFacility>;

#endif
