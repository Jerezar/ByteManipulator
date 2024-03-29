#include "MathCommands.hpp"

#include <exception>
#include <algorithm>

namespace register_fiddler{
    /**
    * First argument is the target register, second is a value as a string or the name of a source register.
    */
    std::string Addition::execute(std::vector<std::string> args){
        
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
            fiddler->add(target, parser->getUnsignedInt(value));
        } else {
        
            if( std::find(regs.begin(), regs.end(), value) == regs.end()){
                return fw_byte_manip::ErrorMessage("Invalid input", value + " is not a valid register").to_string();
            }
            
            fiddler->add(target, value);
        }
        
        return view->display();
    }
    
    std::string Addition::usage(){
        return std::string("<target> <value/source>");
    }
    
    /**
    * First argument is the target register, second is a value as a string or the name of a source register.
    */
    std::string Subtraction::execute(std::vector<std::string> args){
        
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
            fiddler->sub(target, parser->getUnsignedInt(value));
        } else {
            
            if( std::find(regs.begin(), regs.end(), value) == regs.end()){
                return fw_byte_manip::ErrorMessage("Invalid input", value + " is not a valid register").to_string();
            }
            
            fiddler->sub(target, value);
        }
        
        return view->display();
    }
    
    std::string Subtraction::usage(){
        return std::string("<target> <value/source>");
    }
    
    /**
    * First argument is the target register, second is a value as a string or the name of a source register.
    */
    std::string Multiplication::execute(std::vector<std::string> args){
        
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
            fiddler->mul(target, parser->getUnsignedInt(value));
        } else {
        
            if( std::find(regs.begin(), regs.end(), value) == regs.end()){
                return fw_byte_manip::ErrorMessage("Invalid input", value + " is not a valid register").to_string();
            }
            
            fiddler->mul(target, value);
        }
        
        return view->display();
    }
    
    std::string Multiplication::usage(){
        return std::string("<target> <value/source>");
    }
    
    /**
    * First argument is the target register, second is a value as a string or the name of a source register.
    *@throws std::runtime_error if the value or target register are zero
    */
    std::string Division::execute(std::vector<std::string> args){
        
        if( args.size() < 3){
            return fw_byte_manip::ErrorMessage("Missing argument", this->usage() ).to_string();
        }
        
        std::string target = args.at(1);
        
        auto regs = fiddler->getRegisters()->getNames();
        if( std::find(regs.begin(), regs.end(), target) == regs.end()){
            return fw_byte_manip::ErrorMessage("Invalid input", target + " is not a valid register").to_string();
        }
        
        std::string value = args.at(2);
        
        try{
        if(parser->isUnsignedInt(value)){
            fiddler->div(target, parser->getUnsignedInt(value));
        } else {
        
            if( std::find(regs.begin(), regs.end(), value) == regs.end()){
                return fw_byte_manip::ErrorMessage("Invalid input", value + " is not a valid register").to_string();
            }
            
            fiddler->div(target, value);
        }
        } catch (std::logic_error const& e) {
            throw std::runtime_error(e.what());
        }
        
        return view->display();
    }
    
    std::string Division::usage(){
        return std::string("<target> <value/source>");
    }
}
