#ifndef FIDDLERINTERPRETATIONVIEW_HPP
#define FIDDLERINTERPRETATIONVIEW_HPP

#include "MockFiddlerView.hpp"

class FiddlerInterpretationView: public MockFiddlerView{
    public:
    	FiddlerInterpretationView();
        virtual std::string display(Fiddler target) override;
};

#endif
