#include "RegisterMap.hpp"
namespace register_fiddler{
    RegisterMap::RegisterMap( std::vector< std::string > names , uint8_t value){
        for( std::vector< std::string >::iterator iter = names.begin();
        iter < names.end();
        iter++){
            values.emplace(*iter, value);
        }
    }
    
    uint8_t RegisterMap::get(std::string source){
        return values.at(source);
    }
    
    void RegisterMap::set(std::string target, uint8_t value){
        values.at(target) = value;
    }
}
