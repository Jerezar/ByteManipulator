#include "FiddlerFullView.hpp"

FiddlerFullView::FiddlerFullView(){

}

std::string FiddlerFullView::display(Fiddler target){
    std::string result("");
    result += "Byte\tCarry\tZero\tParity\n";
    result += std::to_string(target->byte) + "\t" + std::to_string(target->carry) + "\t" + std::to_string(target->zero) + "\t" + std::to_string(target->parity) + "\n";
    
    return result;
}
