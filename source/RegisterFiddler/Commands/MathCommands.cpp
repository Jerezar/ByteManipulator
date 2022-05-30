#include "MathCommands.hpp"

#include <exception>

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
    
    
    std::string Multiplication::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        if(parser->canParse(value)){
            fiddler->mul(target, parser->getValueFromString(value));
        } else {
            fiddler->mul(target, value);
        }
        
        return view->display();
    }
    
    std::string Multiplication::usage(){
        return std::string("<target> <value/source>");
    }
    
    
    std::string Division::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        try{
        if(parser->canParse(value)){
            fiddler->div(target, parser->getValueFromString(value));
        } else {
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
