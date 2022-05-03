#include "FiddlerInterpretationView.hpp"

#include <bitset>
#include <iostream>
#include <sstream>

#include <iomanip>

FiddlerInterpretationView::FiddlerInterpretationView(){

}

std::string FiddlerInterpretationView::display(Fiddler target){
    std::ostringstream result;
    result << "Byte\t\tOct\tDec\tHex\tChar\t%\tCol\n";
    
    result << std::bitset<8>(target->byte).to_string() << "\t";
    result << std::oct << (int)target->byte << "\t";
    result << std::dec << (int)target->byte << "\t";
    result << std::hex << (int)target->byte <<  "\t";
    result << std::dec;
    result << target->byte << "\t";
    result << std::setprecision(2);
    result << std::fixed;
    result << (100 * (((float)target->byte)/255)) << "\t";
    result << "\u001b[38;5;" << (int)target->byte << "m";
    result << "TEXT";
    result << "\u001b[0m";
    result << std::endl;
    
    return result.str();
}
