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
    
    
    std::string Negate::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        if(args.size() > 2){
            std::string value = args.at(2);
            
            if(parser->canParse(value)){
                fiddler->move(target, parser->getValueFromString(value));
            } else {
                fiddler->move(target, value);
            }
        }
        
        fiddler->negate(target);
        
        return view->display();
    }
    
    std::string Negate::usage(){
        return std::string("<target> None/<value/source>");
    }
    
    
    std::string ToggleBit::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        fiddler->getRegisters()->toggleBit(target, parser->getValueFromString(value));
        
        return view->display();
    }
    
    std::string ToggleBit::usage(){
        return std::string("<target> <bit>");
    }
}
