#ifndef FIDDLERCHANGEVIEW_HPP
#define FIDDLERCHANGEVIEW_HPP

#include "InstructionWrapper.hpp"

#include "FiddlerViewModes.hpp"

class FiddlerChangeView: virtual public InstructionWrapper{
    protected:
        std::shared_ptr<FiddlerViewModes> view;
    public:
        FiddlerChangeView(std::shared_ptr<FiddlerViewModes> _view){
            view = _view;
        };
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

#endif
