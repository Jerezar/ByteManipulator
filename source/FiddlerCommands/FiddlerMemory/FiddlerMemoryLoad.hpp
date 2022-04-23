#ifndef FIDDLERMEMORYLOAD_HPP
#define FIDDLERMEMORYLOAD_HPP

#include "FiddlerCommands/FiddlerMath.hpp"
#include "FiddlerCommands/FiddlerMemory/MemoryCommand.hpp"


class FiddlerMemoryLoad: public FiddlerMath, public MemoryCommand{
    public:
        FiddlerMemoryLoad(Fiddler _target, Mfd_View _view, ValueParser _parser, std::shared_ptr<TypedMemory> _mem): FiddlerMath(_target, _view, _parser), MemoryCommand(_mem){
        }
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

#endif

