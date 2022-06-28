#ifndef CONTROLELEMENT_HPP
#define CONTROLELEMENT_HPP

#include"InputOutputFacility.hpp"
#include "InstructionRegistry.hpp"

#include "Instructions/InstructionSequence.hpp"

namespace fw_byte_manip{
    /**
    * An object that takes input, exececutes commands based on that input, and prints out the results.
    */
    class ControlElement{
        private:
            InputOutputHandler io;
            InstructionSet commandSet;
            
            Instruction preInstruction;
            Instruction postInstruction;
        public:
            /**
            *@param cs The InstructionSet with all additional Commands the program "knows"
            * @param _io The InputOutputHandler over which the program reads input and prints output
            * @param _pre An Instruction that is executed when calling loop(), before the main loop starts. An empty InstructionSequence by default.
            * @param _post An Instruction that is executed when calling loop(), after the loop ends. An empty InstructionSequence by default.
            */
            ControlElement(
                InstructionSet cS, 
                InputOutputHandler _io, 
                Instruction _pre = std::make_shared<fw_byte_manip::InstructionSequence>(std::vector< std::pair< Instruction, std::string > >()), 
                Instruction _post = std::make_shared<fw_byte_manip::InstructionSequence>(std::vector< std::pair< Instruction, std::string > >())
            );
        
            /**
            * The main execution loop
            */
            void loop();
            
            /**
            * The name of the innate quit command, ending the execution loop
            */
            static const std::string quit;
            /**
            * The name of the innate help command, printing the description of all commands.
            */
            static const std::string help;
    };
}
#endif
