#ifndef FIDDLERVIEWMODES_HPP
#define FIDDLERVIEWMODES_HPP

#include "MockFiddlerView.hpp"
#include <map>
#include <vector>

class FiddlerViewModes: public MockFiddlerView{
    private:
        std::map<std::string, Mfd_View> views;
        Mfd_View activeView;
    public:
    	FiddlerViewModes(std::map<std::string, Mfd_View> _views);
        virtual std::string display(Fiddler target) override;
        
        bool changeActiveView(std::string name);
        std::vector<std::string> getNames();
};

#endif
