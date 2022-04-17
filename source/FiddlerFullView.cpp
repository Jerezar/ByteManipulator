#include "FiddlerFullView.hpp"

FiddlerFullView::FiddlerFullView(){

}

std::string FiddlerFullView::display(Fiddler target){
    std::string result("");
    result += "Byte\tCarry\n";
    result += std::to_string(target->byte) + "\t" + std::to_string(target->carry) + "\n";
    
    return result;
}
