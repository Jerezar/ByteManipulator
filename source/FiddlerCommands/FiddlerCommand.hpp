#ifndef FIDDLERCOMMAND_HPP
#define FIDDLERCOMMAND_HPP

#include "InstructionWrapper.hpp"
#include "MockFiddler.hpp"


#include "NumberStringParser.hpp"

#include "MockFiddlerView.hpp"

class FiddlerCommand: public InstructionWrapper{
    protected:
        Fiddler target;
        ValueParser parser;
        Mfd_View view;
    public:
        FiddlerCommand(Fiddler _target){
            target = _target;
        };
};

#endif

