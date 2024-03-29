#include "RegisterFiddler/Commands/LogicCommands.hpp"

#include <algorithm>

namespace register_fiddler{
    /**
    * First argument is the target register, second is a value as a string or the name of a source register.
    */
    std::string And::execute(std::vector<std::string> args){
        
        if( args.size() < 3){
            return fw_byte_manip::ErrorMessage("Missing argument", this->usage() ).to_string();
        }
        
        std::string target = args.at(1);
        
        auto regs = fiddler->getRegisters()->getNames();
        if( std::find(regs.begin(), regs.end(), target) == regs.end()){
            return fw_byte_manip::ErrorMessage("Invalid input", target + " is not a valid register").to_string();
        }
        
        std::string value = args.at(2);
        
        if(parser->isUnsignedInt(value)){
            fiddler->bit_and(target, parser->getUnsignedInt(value));
        } else {
        
            if( std::find(regs.begin(), regs.end(), value) == regs.end()){
                return fw_byte_manip::ErrorMessage("Invalid input", value + " is not a valid register").to_string();
            }
            
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
        
        if( args.size() < 3){
            return fw_byte_manip::ErrorMessage("Missing argument", this->usage() ).to_string();
        }
        
        std::string target = args.at(1);
        
        auto regs = fiddler->getRegisters()->getNames();
        if( std::find(regs.begin(), regs.end(), target) == regs.end()){
            return fw_byte_manip::ErrorMessage("Invalid input", target + " is not a valid register").to_string();
        }
        
        std::string value = args.at(2);
        
        if(parser->isUnsignedInt(value)){
            fiddler->bit_or(target, parser->getUnsignedInt(value));
        } else {
            
            if( std::find(regs.begin(), regs.end(), value) == regs.end()){
                return fw_byte_manip::ErrorMessage("Invalid input", value + " is not a valid register").to_string();
            }
            
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
        
        if( args.size() < 3){
            return fw_byte_manip::ErrorMessage("Missing argument", this->usage() ).to_string();
        }
        
        std::string target = args.at(1);
        
        auto regs = fiddler->getRegisters()->getNames();
        if( std::find(regs.begin(), regs.end(), target) == regs.end()){
            return fw_byte_manip::ErrorMessage("Invalid input", target + " is not a valid register").to_string();
        }
        
        std::string value = args.at(2);
        
        if(parser->isUnsignedInt(value)){
            fiddler->bit_xor(target, parser->getUnsignedInt(value));
        } else {
            
            if( std::find(regs.begin(), regs.end(), value) == regs.end()){
                return fw_byte_manip::ErrorMessage("Invalid input", value + " is not a valid register").to_string();
            }
            
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
        
        if( args.size() < 3){
            return fw_byte_manip::ErrorMessage("Missing argument", this->usage() ).to_string();
        }
        
        std::string target = args.at(1);
        
        auto regs = fiddler->getRegisters()->getNames();
        if( std::find(regs.begin(), regs.end(), target) == regs.end()){
            return fw_byte_manip::ErrorMessage("Invalid input", target + " is not a valid register").to_string();
        }
        
        std::string value = args.at(2);
        
        if(parser->isUnsignedInt(value)){
            fiddler->bit_xnor(target, parser->getUnsignedInt(value));
        } else {
            
            if( std::find(regs.begin(), regs.end(), value) == regs.end()){
                return fw_byte_manip::ErrorMessage("Invalid input", value + " is not a valid register").to_string();
            }
            
            fiddler->bit_xnor(target, value);
        }
        
        return view->display();
    }
    
    std::string Xnor::usage(){
        return std::string("<target> <value/source>");
    }
}
