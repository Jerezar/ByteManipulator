#include "FiddlerChangeView.hpp"
#include <exception>

std::string FiddlerChangeView::execute(std::vector<std::string> args){
    if(args.size() == 1){
        throw std::exception();
        return "";
        
    } else {
        if( args.at(1) == "list"){
            std::string names;
            
            std::vector< std::string > list = view->getNames();
            for(std::vector< std::string >::iterator iter = list.begin();
                iter < list.end();
                iter++){
                names += *iter + "\n";    
            }
            
            return names;
        } else {
            if( !view->changeActiveView(args.at(1))){
                throw std::exception();
                return "";
            } else {
                return "Changed view to " + args.at(1) "\n";
            }
        }
    }
}

std::string FiddlerChangeView::usage(){
    return std::string("list | <name>");
}
