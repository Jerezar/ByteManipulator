#ifndef CONTROLELEMENT_HPP
#define CONTROLELEMENT_HPP

#include"InputOutputFacility.hpp"
#include "InstructionRegistry.hpp"

#include "InstructionSequence.hpp"

class ControlElement{
    private:
        InputOutputHandler io;
        InstructionSet commandSet;
        
        Instruction preInstruction;
        Instruction postInstruction;
    public:
        ControlElement(
            InstructionSet cS, 
            InputOutputHandler _io, 
            Instruction _pre = std::make_shared<fw_byte_manip::InstructionSequence>(std::vector< std::pair< Instruction, std::string > >()), 
            Instruction _post = std::make_shared<fw_byte_manip::InstructionSequence>(std::vector< std::pair< Instruction, std::string > >())
        );
        
        void loop();
        
        static const std::string quit;
        static const std::string help;
};

#endif
