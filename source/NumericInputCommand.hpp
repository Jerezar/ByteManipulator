#ifndef NUMERICINPUTCOMMAND_HPP
#define NUMERICINPUTCOMMAND_HPP

#include "InstructionWrapper.hpp"


#include "NumberStringParser.hpp"

class NumericInputCommand: virtual public InstructionWrapper{
    protected:
        ValueParser parser;
    public:
        NumericInputCommand(ValueParser _parser){
            parser = _parser;
        }
};

#endif

