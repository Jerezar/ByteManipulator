#ifndef FIDDLERCOMMAND_HPP
#define FIDDLERCOMMAND_HPP

#include "InstructionWrapper.hpp"
#include "MockFiddler.hpp"

#include "MockFiddlerView.hpp"

class FiddlerCommand: public InstructionWrapper{
    protected:
        Fiddler target;
        Mfd_View view;
    public:
        FiddlerCommand(Fiddler _target, Mfd_View _view){
            target = _target;
            view = _view;
        };
};

#endif

