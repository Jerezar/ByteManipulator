#include "RegisterFiddler/Commands/MemoryCommands.hpp"

#include <exception>

namespace register_fiddler{
    std::string Load::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        fiddler->load(target, parser->getValueFromString(value));
        
        return view->display();
    }
    
    std::string Load::usage(){
        return std::string("<target> <index>");
    }
    
    
    std::string Save::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        fiddler->save(target, parser->getValueFromString(value));
        
        return view->display();
    }
    
    std::string Save::usage(){
        return std::string("<source> <index>");
    }
}
