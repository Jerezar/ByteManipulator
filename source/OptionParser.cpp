#include "OptionParser.hpp"


namespace fw_byte_manip{
    const std::string OptionParser::prefix = "-";
    
    void OptionParser::addOption(std::string name, unsigned int numArgs){
        options[name] = numArgs;
    }
    
    bool OptionParser::isOption(std::string arg){
        if( arg.find(OptionParser::prefix) == 0){
            return (options.find(arg.substr(OptionParser::prefix.size())) != options.end());
        }
        
        return false;
    }
    
    std::map<std::string, std::vector< std::vector< std::string> > > OptionParser::parseArguments(std::vector<std::string> args, int skip){
        std::map<std::string, std::vector< std::vector< std::string> > > result;
        //All options must be in result, even empty.
        for(std::map<std::string, unsigned int>::iterator optIter = options.begin(); optIter != options.end(); optIter++){
            result[optIter->first] = std::vector< std::vector< std::string> >();
        }
        
        
        //
        for( std::vector<std::string>::iterator iter = args.begin() + skip;
            iter < args.end(); iter++){
            //If there are more than 0 arguments the first should be an option
            if( !isOption(*iter)){
                throw std::runtime_error("Invalid option " + *iter + "\n");
            } else {
                
                std::string arg = *iter;
                std::string argName = arg.substr(OptionParser::prefix.size());
                std::vector<std::string> occurence;
                unsigned int numArgs = options[argName];
                
                
                for( unsigned int i = numArgs; i > 0; i--){
                    
                    iter++;
                    
                    //if an option takes a number of arguments, they must exist, and must not be another option
                    if( iter >= args.end() || isOption(*iter)){
                        throw std::runtime_error("Too few arguments for " + arg + ", takes " + std::to_string(numArgs) + "\n");
                    } else {
                        occurence.push_back(*iter);
                    }
                }
                
                result[argName].push_back(occurence);
            }
        }
        return result;
    }
    
}
