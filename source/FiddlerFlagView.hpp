#ifndef FIDDLERFLAGVIEW_HPP
#define FIDDLERFLAGVIEW_HPP

#include "MockFiddlerView.hpp"

class FiddlerFlagView: public MockFiddlerView{
    public:
    	FiddlerFlagView();
        virtual std::string display(Fiddler target) override;
};

#endif
