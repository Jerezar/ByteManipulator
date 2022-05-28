#include "MathCommands.hpp"
namespace register_fiddler{

    std::string Addition::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        if(parser->canParse(value)){
            fiddler->add(target, parser->getValueFromString(value));
        } else {
            fiddler->add(target, value);
        }
        
        return "\n";
    }
    
    std::string Addition::usage(){
        return std::string("<target> <value/source>");
    }
}
