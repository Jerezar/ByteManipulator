#ifndef INSTRUCTIONSEQUENCE_HPP
#define INSTRUCTIONSEQUENCE_HPP

#include "InstructionWrapper.hpp"

namespace fw_byte_manip{
    /**
    * An Instruction that executes a list of other Instructions with preset arguments.
    */
    class InstructionSequence : public InstructionWrapper{
        private:
            std::vector<std::pair<Instruction, std::string>> list;
        public:
            /**
            * @param _list A vector of string-Intruction-pairs in the order they are to be executed.
            */
            InstructionSequence( std::vector< std::pair< Instruction, std::string > > _list = std::vector< std::pair< Instruction, std::string > >()) { list = _list; };
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
}

#endif
