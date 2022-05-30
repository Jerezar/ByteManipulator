#include "RegisterFiddler/Commands/LogicCommands.hpp"

namespace register_fiddler{
    std::string And::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        if(parser->canParse(value)){
            fiddler->bit_and(target, parser->getValueFromString(value));
        } else {
            fiddler->bit_and(target, value);
        }
        
        return view->display();
    }
    
    std::string And::usage(){
        return std::string("<target> <value/source>");
    }
    
    
    std::string Or::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        if(parser->canParse(value)){
            fiddler->bit_or(target, parser->getValueFromString(value));
        } else {
            fiddler->bit_or(target, value);
        }
        
        return view->display();
    }
    
    std::string Or::usage(){
        return std::string("<target> <value/source>");
    }
    
    
    std::string Xor::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        if(parser->canParse(value)){
            fiddler->bit_xor(target, parser->getValueFromString(value));
        } else {
            fiddler->bit_xor(target, value);
        }
        
        return view->display();
    }
    
    std::string Xor::usage(){
        return std::string("<target> <value/source>");
    }
    
    
    std::string Xnor::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        if(parser->canParse(value)){
            fiddler->bit_xnor(target, parser->getValueFromString(value));
        } else {
            fiddler->bit_xnor(target, value);
        }
        
        return view->display();
    }
    
    std::string Xnor::usage(){
        return std::string("<target> <value/source>");
    }
}
