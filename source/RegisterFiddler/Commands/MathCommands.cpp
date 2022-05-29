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
        
        return view->display();
    }
    
    std::string Addition::usage(){
        return std::string("<target> <value/source>");
    }
    
    
    std::string Subtraction::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        if(parser->canParse(value)){
            fiddler->sub(target, parser->getValueFromString(value));
        } else {
            fiddler->sub(target, value);
        }
        
        return view->display();
    }
    
    std::string Subtraction::usage(){
        return std::string("<target> <value/source>");
    }
}
