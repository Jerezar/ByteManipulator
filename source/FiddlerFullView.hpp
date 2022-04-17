#ifndef FIDDLERFULLVIEW_HPP
#define FIDDLERFULLVIEW_HPP

#include "MockFiddlerView.hpp"

class FiddlerFullView: public MockFiddlerView{
    public:
    	FiddlerFullView();
        virtual std::string display(Fiddler target) override;
};

#endif
