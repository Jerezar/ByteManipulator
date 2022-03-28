#ifndef BYTEMANIPULATOR_HPP
#define BYTEMANIPULATOR_HPP

#include"InputOutputHandler.hpp"
#include "InstructionRegistry.hpp"

class ByteManipulator{
    private:
        InputOutputHandler io;
        InstructionSet commandSet;
    public:
        void loop();
};

#endif
