#include "SwitchView.hpp"

namespace fw_byte_manip {
    const std::string SwitchView::listOption = "list";
    
    std::string SwitchView::execute(std::vector<std::string> args){
        if( args.at(1) == SwitchView::listOption ){
            std::vector< std::string> names = view->getNames();
            std::string list;
            
            for( std::vector< std::string>::iterator iter = names.begin(); iter < names.end(); iter++){
                list += *iter + "\n";
            }
            return list;
        }
        view->setActive(args.at(1));
        
        return view->display();
    }
    
    std::string SwitchView::usage(){
        return SwitchView::listOption + "/<name>";
    }
    
}
