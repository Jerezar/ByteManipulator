#ifndef CONTROLELEMENT_HPP
#define CONTROLELEMENT_HPP

#include"InputOutputFacility.hpp"
#include "InstructionRegistry.hpp"

class ControlElement{
    private:
        InputOutputHandler io;
        InstructionSet commandSet;
    public:
        ControlElement(InstructionSet cS, InputOutputHandler _io);
        void loop();
};

#endif
