#include "FiddlerFullView.hpp"

#include <bitset>

FiddlerFullView::FiddlerFullView(){

}

std::string FiddlerFullView::display(Fiddler target){
    std::string result("");
    result += "Byte\t\tRest\tCarry\tZero\tParity\n";
    result += std::bitset<8>(target->byte).to_string() + "\t" + std::to_string(target->rest) + "\t" + std::to_string(target->carry) + "\t" + std::to_string(target->zero) + "\t" + std::to_string(target->parity) + "\n";
    
    return result;
}
