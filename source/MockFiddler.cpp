#include "MockFiddler.hpp"

void MockFiddler::updateParity(){
    bool result = true;
    for (int i = 0; i < 8; i++){
        if((byte & (1 << i))){
            result = !result;
        }
    }
    parity = result;
}
