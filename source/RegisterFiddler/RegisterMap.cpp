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
    
    std::vector<std::string> RegisterMap::getNames(){
        std::vector< std::string > names;
        for(std::map< std::string, uint8_t >::iterator iter = values.begin(); iter != values.end(); iter++){
            names.push_back(iter->first);
        }
        return names;
    }
    
    void RegisterMap::negate(std::string target) {
        set( target, ~(get(target)) );
    }
    void RegisterMap::toggleBit(std::string target, unsigned int index){
        set( target, (get(target)) ^ (1 << index)) ;
    }
}
