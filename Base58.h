#ifndef BASE58_H
#define BASE58_H

#include <iostream>
#include <cstring>

// This library performs arithmetic operations on large numbers.
// See "https://github.com/elysaccek/Large-Number-Arithmetic-Operations" for details.
#include "LargeNumberOperators.h"

namespace base58{
    
    /**
    * !!! If a non-hexadecimal number is entered, the result is -1, don't forget to check.
    * !!! It uses the LargeNumberOperators.h library to convert hexadecimal numbers to base58 numbers.
    
    * Usage:
    * _hex and _base58 data types (string)
    * base58::HexToBase58(_hex, _base58);
    */
    void HexToBase58(std::string _hex, std::string& _base58){
        bool check = true;
        bool add1 = false;
        int check_len = _hex.length();
        for(int i = 0;i < check_len; i++){
            switch (_hex[i]){
                case '0':break;
                case '1':break;
                case '2':break;
                case '3':break;
                case '4':break;
                case '5':break;
                case '6':break;
                case '7':break;
                case '8':break;
                case '9':break;
                case 'A':break;
                case 'B':break;
                case 'C':break;
                case 'D':break;
                case 'E':break;
                case 'F':break;
                default:check = false;break;
            }
        }
        if(_hex[0] == '0' && _hex[1] == '0')
            add1 = true;

        if(check && check_len != 0){
            _base58 = "0";
            for(int i = 0; i < _hex.length(); i++){
                std::string _d;
                switch (_hex[i]){
                    case '0': _d = "0"; break;
                    case '1': _d = "1"; break;
                    case '2': _d = "2"; break;
                    case '3': _d = "3"; break;
                    case '4': _d = "4"; break;
                    case '5': _d = "5"; break;
                    case '6': _d = "6"; break;
                    case '7': _d = "7"; break;
                    case '8': _d = "8"; break;
                    case '9': _d = "9"; break;
                    case 'A': _d = "10"; break;
                    case 'B': _d = "11"; break;
                    case 'C': _d = "12"; break;
                    case 'D': _d = "13"; break;
                    case 'E': _d = "14"; break;
                    case 'F': _d = "15"; break;
                    default: break;
                }

                lno::Multiplication(_base58,"16",_base58);
                lno::Addition(_base58,_d,_base58);
            }

            std::string _m = "";
            std::string _trush = "";
            int _test = 0;
            while(true){
                lno::Division(_base58,"58",_base58,_m);
                std::string _d;
                switch (std::stoi(_m)){
                    case 0: _d = "1"; break;case 15: _d = "G"; break;case 30: _d = "X"; break;case 45: _d = "n"; break;
                    case 1: _d = "2"; break;case 16: _d = "H"; break;case 31: _d = "Y"; break;case 46: _d = "o"; break;
                    case 2: _d = "3"; break;case 17: _d = "J"; break;case 32: _d = "Z"; break;case 47: _d = "p"; break;
                    case 3: _d = "4"; break;case 18: _d = "K"; break;case 33: _d = "a"; break;case 48: _d = "q"; break;
                    case 4: _d = "5"; break;case 19: _d = "L"; break;case 34: _d = "b"; break;case 49: _d = "r"; break;
                    case 5: _d = "6"; break;case 20: _d = "M"; break;case 35: _d = "c"; break;case 50: _d = "s"; break;
                    case 6: _d = "7"; break;case 21: _d = "N"; break;case 36: _d = "d"; break;case 51: _d = "t"; break;
                    case 7: _d = "8"; break;case 22: _d = "P"; break;case 37: _d = "e"; break;case 52: _d = "u"; break;
                    case 8: _d = "9"; break;case 23: _d = "Q"; break;case 38: _d = "f"; break;case 53: _d = "v"; break;
                    case 9: _d = "A"; break;case 24: _d = "R"; break;case 39: _d = "g"; break;case 54: _d = "w"; break;
                    case 10: _d = "B"; break;case 25: _d = "S"; break;case 40: _d = "h"; break;case 55: _d = "x"; break;
                    case 11: _d = "C"; break;case 26: _d = "T"; break;case 41: _d = "i"; break;case 56: _d = "y"; break;
                    case 12: _d = "D"; break;case 27: _d = "U"; break;case 42: _d = "j"; break;case 57: _d = "z"; break;
                    case 13: _d = "E"; break;case 28: _d = "V"; break;case 43: _d = "k"; break;
                    case 14: _d = "F"; break;case 29: _d = "W"; break;case 44: _d = "m"; break;
                    default: break;
                }
                _trush.insert(0,_d);
                if(_base58 == "0")
                    break;
                _test ++;
            }
            if(add1)
                _base58 = "1" + _trush;
            else
                _base58 = _trush;
        }
        else if(check_len == 0)
            _base58 = "";
        else
            _base58 = "-1";
    }
}

#endif /* BASE58_H */