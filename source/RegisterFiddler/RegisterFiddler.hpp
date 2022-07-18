#ifndef REGISTERFIDDLER_HPP
#define REGISTERFIDDLER_HPP

#include <memory>

#include <string>
#include "FiddlerRegisterBank.hpp"
#include "MemorySpace.hpp"

namespace register_fiddler{
    /**
    * An object with registers, memory and a flag byte.
    * Operations can be used on the registers, updating the flags.
    * Registers can be saved into and overwritten from memory.
    */
    class RegisterFiddler {
        private:
            uint8_t flags;
            int remainder;
            RegisterBank registers;
            MemBlock mem;
        public:
            RegisterFiddler(RegisterBank _registers, MemBlock _mem){
                registers = _registers;
                mem = _mem;
            };
            
            /**
            * @name Bitmasks
            * Bitmasks to isolate each flag from the flag byte.
            */
            /**@{*/
            static const uint8_t carryFlag;
            
            static const uint8_t zeroFlag;
            
            static const uint8_t parityFlag;
            /**@}*/
            
            RegisterBank getRegisters(){ return registers; };
            
            MemBlock getMem(){ return mem; };
            void setMem(MemBlock _mem){ mem = _mem; };
            /**
            * @returns The Value of the target register
            */
            uint8_t get(std::string source);
            
            /**
            *@name Multi register operations
            *Methods that modify a target registers specifically on the basis of another value.
            * Each has one version that takes the second value directly, and one that takes the name of a second register to load it from.
            */
            /**@{*/
            
            /**@{
            * Overwrites the target with the value.
            */
            void move(std::string target, uint8_t value);
            void move(std::string target, std::string source);
            /**@}*/
            
            /**@{
            * Adds the value onto the target.
            */
            void add(std::string target, uint8_t value);
            void add(std::string target, std::string source);
            /**@}*/
            
            
            /**@{
            * Subtracts the value from the target.
            */
            void sub(std::string target, uint8_t value);
            void sub(std::string target, std::string source);
            /**@}*/
            
            /**@{
            * Multiplies the target with the value.
            */
            void mul(std::string target, uint8_t value);
            void mul(std::string target, std::string source);
            /**@}*/
            
            /**@{
            * Divides the target by the value.
            */
            void div(std::string target, uint8_t value);
            void div(std::string target, std::string source);
            /**@}*/
            
            /**@{
            * Sets all bits of the target to false that are not also positive in the value.
            */
            void bit_and(std::string target, uint8_t value);
            void bit_and(std::string target, std::string source);
            /**@}*/
            
            /**@{
            * Sets all bits of the target to true that are true in either target or value.
            */
            void bit_or(std::string target, uint8_t value);
            void bit_or(std::string target, std::string source);
            /**@}*/
            
            /**@{
            * Sets all bits of the target to true that are different to those in the value.
            */
            void bit_xor(std::string target, uint8_t value);
            void bit_xor(std::string target, std::string source);
            /**@}*/
            
            /**@{
            * Sets all bits of the target to true that are the same as those in the value.
            */
            void bit_xnor(std::string target, uint8_t value);
            void bit_xnor(std::string target, std::string source);
            /**@}*/
            /**@}*/
            
            /**
            * @name Single register operations
            */
            /**@{*/
            /**
            * Inverts the target register.
            */
            void negate(std::string target);
            /**
            * Shifts the bitpattern into one direction the specified amount of times.
            * @param left Shift towards the left if true, else shift towards the right.
            */
            void shift(std::string target, bool left = true, unsigned int amount = 1);
            /**
            * Increments or decrements the target.
            * @param up If true, increment, else decrement
            */
            void count(std::string target, bool up = true);
            /**@}*/
            
            /**
            * @name Memory operations
            * Only values in the registers can be modified by the other , these methods move values between registers and memory.
            */
            /**@{*/
            void load(std::string target, unsigned int index);
            void save(std::string source, unsigned int index);
            /**@}*/
            
            /**
            * Checks parity of target register
            */
            bool parity(std::string target);
            void setFlags(uint8_t mask, bool value);
            uint8_t getFlags() { return flags;};
            
    };
    
    using RegFiddler = std::shared_ptr<RegisterFiddler>;
}

#endif
