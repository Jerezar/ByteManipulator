#include "ControlElement.hpp"

#include <memory>

#include <map>
#include <string>

#include "OptionParser.hpp"

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
    
    /*
    * Parsing commandline arguments
    */
    std::vector< std::string > arg (argv, argv + argc);
    
    fw_byte_manip::OptionParser opts;
    opts.addOption("s", 1);
    opts.addOption("d", 1);
    opts.addOption("e", 0);
    
    auto parsedArgs = opts.parseArguments(arg);
    std::string scriptPath;
    bool runScript = parsedArgs["s"].size();
    if(runScript){
        scriptPath = parsedArgs["s"][0][0];
    }
    bool editingMode = parsedArgs["e"].size();
    
    std::string dumpPath;
    bool dumpMem = parsedArgs["d"].size();
    if(dumpMem){
        dumpPath = parsedArgs["d"][0][0];
    }
    
    /*
    * RegisterFiddler creation
    */
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
    
    auto regFidMemory = std::make_shared<register_fiddler::TypedMemorySpace>(0);;
        
    
    register_fiddler::RegFiddler regFid = std::make_shared< register_fiddler::RegisterFiddler >(fidRegisters, regFidMemory
    );
    
    /*
    * RegisterFiddler creation end
    */
    
    
    /*
    * View creation
    */
    
    
    auto registerView = std::make_shared<register_fiddler::ViewRegistersOnly>(regFid);
    auto memoryView = std::make_shared<register_fiddler::ViewMemoryOnly>(regFid);
    
    auto dataView = std::make_shared<fw_byte_manip::CombinedView>(std::vector<fw_byte_manip::View>({ registerView, memoryView }) );
    
    auto regPattern = std::make_shared<register_fiddler::RegisterInterpretationView>(regFid);
    auto memDumpView = std::make_shared<register_fiddler::MemoryInterpretationView>(regFid);
    
    auto interpView = std::make_shared<fw_byte_manip::CombinedView>(std::vector<fw_byte_manip::View>({ regPattern, memDumpView }) );
    
    
    auto registerDisplay = std::make_shared<fw_byte_manip::ViewModes>(std::map< std::string, fw_byte_manip::View>({ {"interpret", interpView},  {"bytes", dataView} }) );
    
    /*
    * View creation end
    */


    ValueParser parser = std::make_shared<StringNumberConverter>();

    auto commands = std::make_shared<fw_byte_manip::InstructionMap>();

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
            {"dump", std::make_shared<register_fiddler::DumpMemory>(regFid, registerDisplay, "./FiddlerMemory.bin")}
        }
    );
    
    commands->registerInstruction(commandMap);
    
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
    
    
    if(editingMode){
        auto extendableMem = std::make_shared<register_fiddler::StringMem>("");
        
        commands->registerInstruction(
            std::map<std::string, fw_byte_manip::Instruction>(
                {
                    {"erase", std::make_shared<register_fiddler::Erase>(extendableMem, registerDisplay, parser)},
                    {"insert", std::make_shared<register_fiddler::Insert>(extendableMem, registerDisplay, parser)}
                }
            )
        );
        
        regFid->setMem( extendableMem );
    }
    
    fw_byte_manip::ControlElement b(commands, io);
    
    auto postInstructions = std::make_shared<fw_byte_manip::InstructionSequence>();
    
    if(dumpMem){
        postInstructions->add( {
            std::make_shared<register_fiddler::DumpMemory>(regFid, registerDisplay, dumpPath), "dump"
        } );
    }
    
    b.setPostInstruction(postInstructions);
    
    b.loop();
    
    return 0;
}
