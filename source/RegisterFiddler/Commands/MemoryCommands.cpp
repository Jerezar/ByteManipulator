#include "RegisterFiddler/Commands/MemoryCommands.hpp"
#include "string_utils.hpp"

#include <exception>

namespace register_fiddler{
    /**
    * Takes two arguments. The first is the target register, the second is the index from which the value is loaded.
    * Unlike RegisterFiddler::load(), this can also take a register name as a second argument, using that value as an index.
    */
    std::string Load::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        if(parser->canParse(value)){
            fiddler->load(target, parser->getValueFromString(value));
        } else {
            fiddler->load(target, fiddler->get(value));
        }
        
        return view->display();
    }
    
    std::string Load::usage(){
        return std::string("<target> <index>");
    }
    
    /**
    * Takes two arguments. The first is the source register, the second is the index into which the value is saved.
    * Unlike RegisterFiddler::save(), this can also take a register name as a second argument, using that value as an index.
    */
    std::string Save::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        if(parser->canParse(value)){
            fiddler->save(target, parser->getValueFromString(value));
        } else {
            fiddler->save(target, fiddler->get(value));
        }
        
        return view->display();
    }
    
    std::string Save::usage(){
        return std::string("<source> <index>");
    }
}
