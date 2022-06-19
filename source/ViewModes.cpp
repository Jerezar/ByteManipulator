#include "ViewModes.hpp"

namespace fw_byte_manip {
    ViewModes::ViewModes( std::map< std::string, View> _views )
    {
        views = _views;
        activeView = views.begin()->second;
    }
    
    /**
    * @throws std::out_of_range
    */
    ViewModes::ViewModes( std::map< std::string, View> _views, std::string first )
    {
        views = _views;
        activeView = views.at(first);
    }
    
    std::string ViewModes::display(){
        return activeView->display();
    }
    
    std::vector< std::string> ViewModes::getNames(){
        std::vector< std::string > result;
        for( std::map< std::string, View>::iterator iter = views.begin(); iter != views.end(); iter++){
            result.push_back(iter->first);
        }
        return result;
    }
    
    void ViewModes::setActive(std::string name){
        std::map< std::string, View>::iterator toBeSet = views.find(name);
        
        if(toBeSet != views.end()){
            activeView = toBeSet->second;
        }
    }
}
