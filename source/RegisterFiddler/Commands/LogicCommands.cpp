#include "RegisterFiddler/Commands/LogicCommands.hpp"

namespace register_fiddler{
    /**
    * First argument is the target register, second is a value as a string or the name of a source register.
    */
    std::string And::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        if(parser->isUnsignedInt(value)){
            fiddler->bit_and(target, parser->getUnsignedInt(value));
        } else {
            fiddler->bit_and(target, value);
        }
        
        return view->display();
    }
    
    std::string And::usage(){
        return std::string("<target> <value/source>");
    }
    
    /**
    * First argument is the target register, second is a value as a string or the name of a source register.
    */
    std::string Or::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        if(parser->isUnsignedInt(value)){
            fiddler->bit_or(target, parser->getUnsignedInt(value));
        } else {
            fiddler->bit_or(target, value);
        }
        
        return view->display();
    }
    
    std::string Or::usage(){
        return std::string("<target> <value/source>");
    }
    
    /**
    * First argument is the target register, second is a value as a string or the name of a source register.
    */
    std::string Xor::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        if(parser->isUnsignedInt(value)){
            fiddler->bit_xor(target, parser->getUnsignedInt(value));
        } else {
            fiddler->bit_xor(target, value);
        }
        
        return view->display();
    }
    
    std::string Xor::usage(){
        return std::string("<target> <value/source>");
    }
    
    /**
    * First argument is the target register, second is a value as a string or the name of a source register.
    */
    std::string Xnor::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        if(parser->isUnsignedInt(value)){
            fiddler->bit_xnor(target, parser->getUnsignedInt(value));
        } else {
            fiddler->bit_xnor(target, value);
        }
        
        return view->display();
    }
    
    std::string Xnor::usage(){
        return std::string("<target> <value/source>");
    }
}
