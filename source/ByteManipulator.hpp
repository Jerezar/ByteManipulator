#ifndef BYTEMANIPULATOR_HPP
#define BYTEMANIPULATOR_HPP

#include"InputOutputFacility.hpp"
#include "InstructionRegistry.hpp"

class ByteManipulator{
    private:
        InputOutputHandler io;
        InstructionSet commandSet;
    public:
        ByteManipulator(InstructionSet cS, InputOutputHandler _io);
        void loop();
};

#endif
