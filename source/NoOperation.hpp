#ifndef NOOPERATION_HPP
#define NOOPERATION_HPP

#include "InstructionWrapper.hpp"


namespace fw_byte_manip{
    /**
    * An Instruction that does nothing.
    */
    class NoOperation : public InstructionWrapper{
        public:
            NoOperation();
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
}
#endif
