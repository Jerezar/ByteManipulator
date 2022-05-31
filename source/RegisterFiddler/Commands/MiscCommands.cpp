#include "RegisterFiddler/Commands/MiscCommands.hpp"

namespace register_fiddler{
    std::string Move::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        if(parser->canParse(value)){
            fiddler->move(target, parser->getValueFromString(value));
        } else {
            fiddler->move(target, value);
        }
        
        return view->display();
    }
    
    std::string Move::usage(){
        return std::string("<target> <value/source>");
    }
}
