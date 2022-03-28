#include "ByteManipulator.hpp"

#include <string>

void ByteManipulator::loop(){
    while (true){
        std::string input = io.read("Input: ");
        
        io.print("Echo " + input);
    }
}
