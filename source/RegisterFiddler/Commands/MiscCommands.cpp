#include "RegisterFiddler/Commands/MiscCommands.hpp"

#include <exception>

namespace register_fiddler{
    /**
    * First argument is the target register, second is a value as a string or the name of a source register.
    */
    std::string Move::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        if(parser->isUnsignedInt(value)){
            fiddler->move(target, parser->getUnsignedInt(value));
        } else {
            fiddler->move(target, value);
        }
        
        return view->display();
    }
    
    std::string Move::usage(){
        return std::string("<target> <value/source>");
    }
    
    /**
    * First argument is the target register.
    * Opionally takes a register name as a second argument, which makes this instruction move the value of the target register into the second register and then negates that one.
    */
    std::string Negate::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        if(args.size() > 2){
            std::string value = args.at(2);
            
            if(parser->isUnsignedInt(value)){
                fiddler->move(target, parser->getUnsignedInt(value));
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
    
    /**
    * First argument is the target register, second is the index of the bit (starts at 0).
    */
    std::string ToggleBit::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        fiddler->getRegisters()->toggleBit(target, parser->getUnsignedInt(value));
        
        return view->display();
    }
    
    std::string ToggleBit::usage(){
        return std::string("<target> <bit>");
    }
    
    
    const std::string Shift::leftward = "left";
    const std::string Shift::rightward = "right";
    
    /**
    * First argument is the target register, second is either Shift::leftward or Shift::rightward.
    * Optionally takes a number as a third argument, the amount of times the register is shifted.
    *@throws std::runtime_error if the second argument is not either of the valid inputs.
    */
    std::string Shift::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string direction = args.at(2);
        
        unsigned int amount = 1;
        if(args.size() > 3){
            std::string value = args.at(3);
            amount = parser->getUnsignedInt(value);
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
    /**
    * First argument is the target register, second is either Count::upward or Count::downward.
    *@throws std::runtime_error if the second argument is not either of the valid inputs.
    */
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
