#ifndef NOOPERATION_HPP
#define NOOPERATION_HPP

#include "InstructionWrapper.hpp"

class NoOperation : public InstructionWrapper{
    public:
        virtual std::string execute(std::vector<std::string> args) override;
};

#endif
