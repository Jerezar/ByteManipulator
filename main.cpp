#include "ControlElement.hpp"

#include <memory>

#include <map>
#include <string>

#include "InstructionRegistry.hpp"
#include "InstructionMap.hpp"

#include "InstructionWrapper.hpp"

#include "NumberStringParser.hpp"
#include "StringNumberConverter.hpp"

#include "InputOutputFacility.hpp"
#include "InputLogger.hpp"
#include "OutputLogger.hpp"
#include "StandardStreamHandler.hpp"
#include "ScriptReader.hpp"
#include "RunScript.hpp"

#include "RegisterFiddler/RegisterFiddler.hpp"
#include "RegisterFiddler/RegisterMap.hpp"
#include "RegisterFiddler/StringMem.hpp"
#include "RegisterFiddler/TypedMemorySpace.hpp"

#include "ViewModes.hpp"
#include "CombinedView.hpp"
#include "RegisterFiddler/ViewRegistersOnly.hpp"
#include "RegisterFiddler/ViewMemoryOnly.hpp"
#include "RegisterFiddler/RegisterInterpretationView.hpp"
#include "RegisterFiddler/MemoryInterpretationView.hpp"

#include "SwitchView.hpp"
#include "RegisterFiddler/Commands/MathCommands.hpp"
#include "RegisterFiddler/Commands/LogicCommands.hpp"
#include "RegisterFiddler/Commands/MiscCommands.hpp"
#include "RegisterFiddler/Commands/MemoryCommands.hpp"

int main(int argc, char* argv[]){
    
    std::vector< std::string > arg (argv, argv + argc);
    
    std::string scriptPath;
    bool runScript = false;
    
    for( std::vector< std::string >::iterator iter = arg.begin(); iter < arg.end(); iter++){
        std::cout << *iter << std::endl;
        if( *iter == "-s"){
            ++iter;
            if(iter < arg.end()){
                runScript = true;
                scriptPath = *iter;
            }
        }
    }
    
    auto fidRegisters = std::make_shared< register_fiddler::RegisterMap >(
        std::vector< std::string >(
            {
                "ra",
                "rb",
                "rc",
                "re"
            }
        )
    );
    
    auto regFidMemory = std::make_shared<register_fiddler::StringMem>("");
    
    register_fiddler::RegFiddler regFid = std::make_shared< register_fiddler::RegisterFiddler >(fidRegisters, regFidMemory
    );
    
    auto registerView = std::make_shared<register_fiddler::ViewRegistersOnly>(regFid);
    auto memoryView = std::make_shared<register_fiddler::ViewMemoryOnly>(regFid);
    
    auto dataView = std::make_shared<fw_byte_manip::CombinedView>(std::vector<fw_byte_manip::View>({ registerView, memoryView }) );
    
    auto regPattern = std::make_shared<register_fiddler::RegisterInterpretationView>(regFid);
    auto memDumpView = std::make_shared<register_fiddler::MemoryInterpretationView>(regFid);
    
    auto interpView = std::make_shared<fw_byte_manip::CombinedView>(std::vector<fw_byte_manip::View>({ regPattern, memDumpView }) );
    
    
    auto registerDisplay = std::make_shared<fw_byte_manip::ViewModes>(std::map< std::string, fw_byte_manip::View>({ {"interpret", interpView},  {"bytes", dataView} }) );


    ValueParser parser = std::make_shared<StringNumberConverter>();


    std::map<std::string, fw_byte_manip::Instruction> commandMap(
        {
            {"add", std::make_shared<register_fiddler::Addition>(regFid, registerDisplay, parser)},
            {"sub", std::make_shared<register_fiddler::Subtraction>(regFid, registerDisplay, parser)},
            {"mul", std::make_shared<register_fiddler::Multiplication>(regFid, registerDisplay, parser)},
            {"div", std::make_shared<register_fiddler::Division>(regFid, registerDisplay, parser)},
            {"and", std::make_shared<register_fiddler::And>(regFid, registerDisplay, parser)},
            {"or", std::make_shared<register_fiddler::Or>(regFid, registerDisplay, parser)},
            {"xor", std::make_shared<register_fiddler::Xor>(regFid, registerDisplay, parser)},
            {"xnor", std::make_shared<register_fiddler::Xnor>(regFid, registerDisplay, parser)},
            {"move", std::make_shared<register_fiddler::Move>(regFid, registerDisplay, parser)},
            {"neg", std::make_shared<register_fiddler::Negate>(regFid, registerDisplay, parser)},
            {"set", std::make_shared<register_fiddler::ToggleBit>(regFid, registerDisplay, parser)},
            {"shift", std::make_shared<register_fiddler::Shift>(regFid, registerDisplay, parser)},
            {"count", std::make_shared<register_fiddler::Count>(regFid, registerDisplay, parser)},
            {"save", std::make_shared<register_fiddler::Save>(regFid, registerDisplay, parser)},
            {"load", std::make_shared<register_fiddler::Load>(regFid, registerDisplay, parser)},
            {"view", std::make_shared<fw_byte_manip::SwitchView>(registerDisplay)},
            {"write", std::make_shared<register_fiddler::Write>(regFid, registerDisplay, parser)},
            {"erase", std::make_shared<register_fiddler::Erase>(regFidMemory, registerDisplay, parser)},
            {"insert", std::make_shared<register_fiddler::Insert>(regFidMemory, registerDisplay, parser)},
            {"dump", std::make_shared<register_fiddler::DumpMemory>(regFid, registerDisplay, "./FiddlerMemory.bin")}
        }
    );

    auto commands = std::make_shared<fw_byte_manip::InstructionMap>(commandMap);
    
    commands->registerInstruction(
            "run", std::make_shared<fw_byte_manip::RunScript>(commands));
    
    fw_byte_manip::InputOutputHandler io;
    
    if(runScript){
        auto script = std::make_shared<fw_byte_manip::ScriptReader>(scriptPath);
        io = std::make_shared<fw_byte_manip::OutputLogger>( script, "./OutputFile.txt", false);
    } else {
        auto userInput = std::make_shared<fw_byte_manip::StandardStreamHandler>();
        io = std::make_shared<fw_byte_manip::InputLogger>( userInput, "./InputLog.txt"); 
    }
    
    fw_byte_manip::ControlElement b(commands, io);
    
    b.loop();
    
    return 0;
}
