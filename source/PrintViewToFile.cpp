#include "PrintViewToFile.hpp"


#include <fstream>

namespace fw_byte_manip {
    /**
    * Prints the View into the target file.
    * Takes a path as an optional argument.
    */
    std::string PrintViewToFile::execute(std::vector<std::string> args){
        std::string result;
        std::fstream file;
        
        std::string targetPath = defaultPath;
        
        if(args.size() > 1){
            targetPath = args.at(1);
        }
        
        file.open(targetPath, (std::ios_base::out | std::ios_base::app));
        
        if(file.is_open()){
            file << view->display();
            result += "View saved to " + targetPath + "\n";
        }
        
        file.close();
        return result + view->display();
    }
    
    std::string PrintViewToFile::usage(){
        return "<path>";
    }
    
}
