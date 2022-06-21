#include <vector>
#include <stdint.h>

namespace register_fiddler{
    template <typename T>
    std::vector<uint8_t> toByteVector(std::vector<T> vec){
        std::vector<uint8_t> result;
        int size = sizeof(T);
        
        for(typename std::vector<T>::iterator iter = vec.begin(); iter < vec.end(); iter++){
            T obj = *iter;
            for (int i=0; i<size; i++){
                result.push_back( reinterpret_cast<uint8_t*>(&obj)[size - 1 - i] );
            }
        }
        return result;
    }
    
    template <typename T>
    std::vector<T> fromByteVector(std::vector<uint8_t> vec){
        std::vector<T> result;
        int size = sizeof(T);
        std::vector<uint8_t>::iterator iter = vec.begin();
        
        while(iter < vec.end()){
            T obj;
            for(int i = 0; i < size && iter < vec.end(); i++){
                reinterpret_cast<uint8_t*>(&obj)[size - 1 - i] = (*iter);
                
                iter++;
            }
            result.push_back(obj);
        }
         return result;
    }
}
