#include "string_utils.hpp"

namespace fw_byte_manip{
    namespace string_utils{
    
        std::vector< std::string > split(std::string input, std::string delim){
            std::vector<std::string> result;
            
            while( !input.empty() ){
                size_t pos = input.find(delim);
                
                result.push_back(input.substr(0, pos));
                
                input.erase(0, pos);        //getrennt, falls pos string::npos ist
                input.erase(0, delim.length());
            }
            
            return result;
        }
        
        
        //This is horrible, I am sorry
        /*
        std::string iso_8859_1_escape(uint8_t value){
            switch(value){
                case 0x00: return "\u0000";
                case 0x01: return "\u0001";
                case 0x02: return "\u0002";
                case 0x03: return "\u0003";
                case 0x04: return "\u0004";
                case 0x05: return "\u0005";
                case 0x06: return "\u0006";
                case 0x07: return "\u0007";
                case 0x08: return "\u0008";
                case 0x09: return "\u0009";
                case 0x0a: return "\u000a";
                case 0x0b: return "\u000b";
                case 0x0c: return "\u000c";
                case 0x0d: return "\u000d";
                case 0x0e: return "\u000e";
                case 0x0f: return "\u000f";
                case 0x10: return "\u0010";
                case 0x11: return "\u0011";
                case 0x12: return "\u0012";
                case 0x13: return "\u0013";
                case 0x14: return "\u0014";
                case 0x15: return "\u0015";
                case 0x16: return "\u0016";
                case 0x17: return "\u0017";
                case 0x18: return "\u0018";
                case 0x19: return "\u0019";
                case 0x1a: return "\u001a";
                case 0x1b: return "\u001b";
                case 0x1c: return "\u001c";
                case 0x1d: return "\u001d";
                case 0x1e: return "\u001e";
                case 0x1f: return "\u001f";
                case 0x20: return "\u0020";
                case 0x21: return "\u0021";
                case 0x22: return "\u0022";
                case 0x23: return "\u0023";
                case 0x24: return "\u0024";
                case 0x25: return "\u0025";
                case 0x26: return "\u0026";
                case 0x27: return "\u0027";
                case 0x28: return "\u0028";
                case 0x29: return "\u0029";
                case 0x2a: return "\u002a";
                case 0x2b: return "\u002b";
                case 0x2c: return "\u002c";
                case 0x2d: return "\u002d";
                case 0x2e: return "\u002e";
                case 0x2f: return "\u002f";
                case 0x30: return "\u0030";
                case 0x31: return "\u0031";
                case 0x32: return "\u0032";
                case 0x33: return "\u0033";
                case 0x34: return "\u0034";
                case 0x35: return "\u0035";
                case 0x36: return "\u0036";
                case 0x37: return "\u0037";
                case 0x38: return "\u0038";
                case 0x39: return "\u0039";
                case 0x3a: return "\u003a";
                case 0x3b: return "\u003b";
                case 0x3c: return "\u003c";
                case 0x3d: return "\u003d";
                case 0x3e: return "\u003e";
                case 0x3f: return "\u003f";
                case 0x40: return "\u0040";
                case 0x41: return "\u0041";
                case 0x42: return "\u0042";
                case 0x43: return "\u0043";
                case 0x44: return "\u0044";
                case 0x45: return "\u0045";
                case 0x46: return "\u0046";
                case 0x47: return "\u0047";
                case 0x48: return "\u0048";
                case 0x49: return "\u0049";
                case 0x4a: return "\u004a";
                case 0x4b: return "\u004b";
                case 0x4c: return "\u004c";
                case 0x4d: return "\u004d";
                case 0x4e: return "\u004e";
                case 0x4f: return "\u004f";
                case 0x50: return "\u0050";
                case 0x51: return "\u0051";
                case 0x52: return "\u0052";
                case 0x53: return "\u0053";
                case 0x54: return "\u0054";
                case 0x55: return "\u0055";
                case 0x56: return "\u0056";
                case 0x57: return "\u0057";
                case 0x58: return "\u0058";
                case 0x59: return "\u0059";
                case 0x5a: return "\u005a";
                case 0x5b: return "\u005b";
                case 0x5c: return "\u005c";
                case 0x5d: return "\u005d";
                case 0x5e: return "\u005e";
                case 0x5f: return "\u005f";
                case 0x60: return "\u0060";
                case 0x61: return "\u0061";
                case 0x62: return "\u0062";
                case 0x63: return "\u0063";
                case 0x64: return "\u0064";
                case 0x65: return "\u0065";
                case 0x66: return "\u0066";
                case 0x67: return "\u0067";
                case 0x68: return "\u0068";
                case 0x69: return "\u0069";
                case 0x6a: return "\u006a";
                case 0x6b: return "\u006b";
                case 0x6c: return "\u006c";
                case 0x6d: return "\u006d";
                case 0x6e: return "\u006e";
                case 0x6f: return "\u006f";
                case 0x70: return "\u0070";
                case 0x71: return "\u0071";
                case 0x72: return "\u0072";
                case 0x73: return "\u0073";
                case 0x74: return "\u0074";
                case 0x75: return "\u0075";
                case 0x76: return "\u0076";
                case 0x77: return "\u0077";
                case 0x78: return "\u0078";
                case 0x79: return "\u0079";
                case 0x7a: return "\u007a";
                case 0x7b: return "\u007b";
                case 0x7c: return "\u007c";
                case 0x7d: return "\u007d";
                case 0x7e: return "\u007e";
                case 0x7f: return "\u007f";
                case 0x80: return "\u0080";
                case 0x81: return "\u0081";
                case 0x82: return "\u0082";
                case 0x83: return "\u0083";
                case 0x84: return "\u0084";
                case 0x85: return "\u0085";
                case 0x86: return "\u0086";
                case 0x87: return "\u0087";
                case 0x88: return "\u0088";
                case 0x89: return "\u0089";
                case 0x8a: return "\u008a";
                case 0x8b: return "\u008b";
                case 0x8c: return "\u008c";
                case 0x8d: return "\u008d";
                case 0x8e: return "\u008e";
                case 0x8f: return "\u008f";
                case 0x90: return "\u0090";
                case 0x91: return "\u0091";
                case 0x92: return "\u0092";
                case 0x93: return "\u0093";
                case 0x94: return "\u0094";
                case 0x95: return "\u0095";
                case 0x96: return "\u0096";
                case 0x97: return "\u0097";
                case 0x98: return "\u0098";
                case 0x99: return "\u0099";
                case 0x9a: return "\u009a";
                case 0x9b: return "\u009b";
                case 0x9c: return "\u009c";
                case 0x9d: return "\u009d";
                case 0x9e: return "\u009e";
                case 0x9f: return "\u009f";
                case 0xa0: return "\u00a0";
                case 0xa1: return "\u00a1";
                case 0xa2: return "\u00a2";
                case 0xa3: return "\u00a3";
                case 0xa4: return "\u00a4";
                case 0xa5: return "\u00a5";
                case 0xa6: return "\u00a6";
                case 0xa7: return "\u00a7";
                case 0xa8: return "\u00a8";
                case 0xa9: return "\u00a9";
                case 0xaa: return "\u00aa";
                case 0xab: return "\u00ab";
                case 0xac: return "\u00ac";
                case 0xad: return "\u00ad";
                case 0xae: return "\u00ae";
                case 0xaf: return "\u00af";
                case 0xb0: return "\u00b0";
                case 0xb1: return "\u00b1";
                case 0xb2: return "\u00b2";
                case 0xb3: return "\u00b3";
                case 0xb4: return "\u00b4";
                case 0xb5: return "\u00b5";
                case 0xb6: return "\u00b6";
                case 0xb7: return "\u00b7";
                case 0xb8: return "\u00b8";
                case 0xb9: return "\u00b9";
                case 0xba: return "\u00ba";
                case 0xbb: return "\u00bb";
                case 0xbc: return "\u00bc";
                case 0xbd: return "\u00bd";
                case 0xbe: return "\u00be";
                case 0xbf: return "\u00bf";
                case 0xc0: return "\u00c0";
                case 0xc1: return "\u00c1";
                case 0xc2: return "\u00c2";
                case 0xc3: return "\u00c3";
                case 0xc4: return "\u00c4";
                case 0xc5: return "\u00c5";
                case 0xc6: return "\u00c6";
                case 0xc7: return "\u00c7";
                case 0xc8: return "\u00c8";
                case 0xc9: return "\u00c9";
                case 0xca: return "\u00ca";
                case 0xcb: return "\u00cb";
                case 0xcc: return "\u00cc";
                case 0xcd: return "\u00cd";
                case 0xce: return "\u00ce";
                case 0xcf: return "\u00cf";
                case 0xd0: return "\u00d0";
                case 0xd1: return "\u00d1";
                case 0xd2: return "\u00d2";
                case 0xd3: return "\u00d3";
                case 0xd4: return "\u00d4";
                case 0xd5: return "\u00d5";
                case 0xd6: return "\u00d6";
                case 0xd7: return "\u00d7";
                case 0xd8: return "\u00d8";
                case 0xd9: return "\u00d9";
                case 0xda: return "\u00da";
                case 0xdb: return "\u00db";
                case 0xdc: return "\u00dc";
                case 0xdd: return "\u00dd";
                case 0xde: return "\u00de";
                case 0xdf: return "\u00df";
                case 0xe0: return "\u00e0";
                case 0xe1: return "\u00e1";
                case 0xe2: return "\u00e2";
                case 0xe3: return "\u00e3";
                case 0xe4: return "\u00e4";
                case 0xe5: return "\u00e5";
                case 0xe6: return "\u00e6";
                case 0xe7: return "\u00e7";
                case 0xe8: return "\u00e8";
                case 0xe9: return "\u00e9";
                case 0xea: return "\u00ea";
                case 0xeb: return "\u00eb";
                case 0xec: return "\u00ec";
                case 0xed: return "\u00ed";
                case 0xee: return "\u00ee";
                case 0xef: return "\u00ef";
                case 0xf0: return "\u00f0";
                case 0xf1: return "\u00f1";
                case 0xf2: return "\u00f2";
                case 0xf3: return "\u00f3";
                case 0xf4: return "\u00f4";
                case 0xf5: return "\u00f5";
                case 0xf6: return "\u00f6";
                case 0xf7: return "\u00f7";
                case 0xf8: return "\u00f8";
                case 0xf9: return "\u00f9";
                case 0xfa: return "\u00fa";
                case 0xfb: return "\u00fb";
                case 0xfc: return "\u00fc";
                case 0xfd: return "\u00fd";
                case 0xfe: return "\u00fe";
                case 0xff: return "\u00ff";
            }
            return "";
        }
        */
        
        std::string ansi_8b_col_text(std::string text, uint8_t value){
            return "\u001b[38;5;" + std::to_string(value) + "m" + text + "\u001b[0m"; 
        }
        
        std::string ansi_8b_col_bg(std::string text, uint8_t value){
            return "\u001b[48;5;" + std::to_string(value) + "m" + text + "\u001b[0m"; 
        }
    }
}
