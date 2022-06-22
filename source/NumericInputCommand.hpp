#ifndef NUMERICINPUTCOMMAND_HPP
#define NUMERICINPUTCOMMAND_HPP

#include "InstructionWrapper.hpp"


#include "NumberStringParser.hpp"

namespace fw_byte_manip{
    /**
    * An Instruction that takes string representations of numbers as arguments in some form.
    */
    class NumericInputCommand: virtual public InstructionWrapper{
        protected:
            ValueParser parser;
        public:
            /**
            * The ValueParser the Instruction uses to convert a string into a value.
            */
            NumericInputCommand(ValueParser _parser){
                parser = _parser;
            }
    };
}
#endif

