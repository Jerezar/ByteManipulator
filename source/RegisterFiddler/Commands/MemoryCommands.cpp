#include "RegisterFiddler/Commands/MemoryCommands.hpp"
#include "string_utils.hpp"

#include <exception>
#include <algorithm>

namespace register_fiddler{
    /**
    * Takes two arguments. The first is the target register, the second is the index from which the value is loaded.
    * Unlike RegisterFiddler::load(), this can also take a register name as a second argument, using that value as an index.
    */
    std::string Load::execute(std::vector<std::string> args){
        std::string target = args.at(1);
        
        std::string value = args.at(2);
        
        if(parser->isUnsignedInt(value)){
            fiddler->load(target, parser->getUnsignedInt(value));
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
        
        if(parser->isUnsignedInt(value)){
            fiddler->save(target, parser->getUnsignedInt(value));
        } else {
            fiddler->save(target, fiddler->get(value));
        }
        
        return view->display();
    }
    
    std::string Save::usage(){
        return std::string("<source> <index>");
    }
    
    
    const std::string Write::listOption("types");
    const std::vector<std::string> Write::types( {"u16", "u32", "u64", "str"} );
    
    std::string Write::execute(std::vector<std::string> args){
        std::string index;
        std::string type;
        std::string val;
        
        if(args.size() == 2 && args.at(1) == Write::listOption){
            std::string typeList;
            for(std::vector<std::string>::const_iterator iter = Write::types.begin(); iter < Write::types.end(); iter++){
                typeList += *iter + "\n";
            }
            return typeList;
        } else if(args.size() >= 4){
            index = args.at(1);
            type = args.at(2);
            val = args.at(3);
        } else {
            return fw_byte_manip::ErrorMessage("Missing argument", this->usage() ).to_string();
        }
        
        if(!parser->isUnsignedInt(index)){
            return fw_byte_manip::ErrorMessage("Invalid input", "Must be a valid index" ).to_string();
        }
        
        if(std::find(Write::types.begin(), Write::types.end(), type) ==  Write::types.end()){
            return fw_byte_manip::ErrorMessage("Invalid input", "Must be a valid type (see option \" " + Write::listOption + "\")").to_string();
        } else {
            
            ByteChain b;
            if(type == Write::types[0]){
                uint16_t num = parser->getUnsignedInt(val);
                b = ByteChain(&num, sizeof(num));
            } else if(type == Write::types[1]){
                uint32_t num = parser->getUnsignedInt(val);
                b = ByteChain(&num, sizeof(num));
            } else if(type == Write::types[2]){
                uint64_t num = parser->getUnsignedInt(val);
                b = ByteChain(&num, sizeof(num));
            } else if(type == Write::types[3]){
                b = ByteChain(std::vector<uint8_t>(val.begin(), val.end()));
            }
            
            fiddler->getMem()->write(b, parser->getUnsignedInt(index));
        }
        
        return view->display();
    }
    
    std::string Write::usage(){
        return std::string("<index> <type> <value>");
    }
    
    
    std::string Erase::execute(std::vector<std::string> args){
        unsigned int index;
        unsigned int length = 1;
        
        if(args.size() < 2){
            return fw_byte_manip::ErrorMessage("Missing argument", this->usage() ).to_string();
        }
        
        if(parser->isUnsignedInt(args.at(1))){
            index = parser->getUnsignedInt(args.at(1));
        } else {
            return fw_byte_manip::ErrorMessage("Invalid input", "Must be a valid index" ).to_string();
        }
        
        if(args.size() >= 3){
            if(parser->isUnsignedInt(args.at(2))){
                length = parser->getUnsignedInt(args.at(2));
            } else {
                return fw_byte_manip::ErrorMessage("Invalid input", "Must be a positive integer" ).to_string();
            }
        }
        
        mem->erase(index, length);
        
        return view->display();
    }
    
    std::string Erase::usage(){
        return "<index> <length>";
    }
    
    std::string Insert::execute(std::vector<std::string> args){
        unsigned int index;
        uint8_t val;
        unsigned int length = 1;
        
        if(args.size() < 2){
            return fw_byte_manip::ErrorMessage("Missing argument", this->usage() ).to_string();
        }
        
        if(parser->isUnsignedInt(args.at(1))){
            index = parser->getUnsignedInt(args.at(1));
        } else {
            return fw_byte_manip::ErrorMessage("Invalid input", "Must be a valid index" ).to_string();
        }
        
        if(parser->isUnsignedInt(args.at(2))){
            val = parser->getUnsignedInt(args.at(2));
        } else {
            return fw_byte_manip::ErrorMessage("Invalid input", "Must be a positive integer" ).to_string();
        }
        
        if(args.size() >= 4){
            if(parser->isUnsignedInt(args.at(3))){
                length = parser->getUnsignedInt(args.at(3));
            } else {
                return fw_byte_manip::ErrorMessage("Invalid input", "Must be a positive integer" ).to_string();
            }
        }
        
        mem->insert(index, length, val);
        
        return view->display();
    }
    
    std::string Insert::usage(){
        return "<index> <value> <length>";
    }
}
