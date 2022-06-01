#include "RegisterFiddler/Commands/MiscCommands.hpp"

#include <exception>

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
    
    
    const std::string Shift::leftward = "left";
    const std::string Shift::rightward = "right";
    
    std::string Shift::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string direction = args.at(2);
        
        unsigned int amount = 1;
        if(args.size() > 3){
            std::string value = args.at(3);
            amount = parser->getValueFromString(value);
        }
        
        if( direction == Shift::leftward ){
            fiddler->shift(target, true, amount);
        } else if( direction == Shift::rightward ){
            fiddler->shift(target, false, amount);
        } else {
            throw std::runtime_error("Invalid direction\n");
        }
        
        return view->display();
    }
    
    std::string Shift::usage(){
        return std::string("<target> <" + leftward + "/" + rightward + "> <amount>");
    }
    
    
    const std::string Count::upward = "inc";
    const std::string Count::downward = "dec";
    
    std::string Count::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string direction = args.at(2);
        
        if( direction == Count::upward ){
            fiddler->count(target, true);
        } else if( direction == Count::downward ){
            fiddler->count(target, false);
        } else {
            throw std::runtime_error("Invalid direction\n");
        }
        
        return view->display();
    }
    
    std::string Count::usage(){
        return std::string("<target> <" + upward + "/" + downward + ">");
    }
}
