#ifndef FIDDLERCOMMAND_HPP
#define FIDDLERCOMMAND_HPP

#include "InstructionWrapper.hpp"
#include "MockFiddler.hpp"

class FiddlerCommand: public InstructionWrapper{
    protected:
        Fiddler target;
    public:
        FiddlerCommand(Fiddler _target){
            target = _target;
        };
};

#endif

