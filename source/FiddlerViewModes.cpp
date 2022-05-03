#include "FiddlerViewModes.hpp"

FiddlerViewModes::FiddlerViewModes(std::map<std::string, Mfd_View> _views){
    views = _views;
    activeView = views.begin()->second;
}

std::string FiddlerViewModes::display(Fiddler target) {
    return activeView->display(target);
}

bool FiddlerViewModes::changeActiveView(std::string name){
    std::map<std::string, Mfd_View>::iterator target = views.find(name);
    
    if(target != views.end()){
        activeView = target->second;
        return true;
    }
    
    return false;
}

std::vector<std::string> FiddlerViewModes::getNames(){
    std::vector<std::string> result;
    
    for(std::map<std::string, Mfd_View>::iterator iter = views.begin(); iter != views.end(); iter++){
        result.push_back(iter->first);
    }
    
    return result;
}
