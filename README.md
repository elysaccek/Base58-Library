# Base58 Library
This **Base58 Library** is for converting texts and large hexadecimal numbers to base58.

## Notes
Currently it only converts hexadecimal numbers to base58.

## What's Needed
LargeNumberOperators.h library is needed. This library is used to perform 
arithmetic operations on large numbers. It doesn't need anything else.

## LargeNumberOperators.h
For detailed information and library installation, 
see "https://github.com/elysaccek/Large-Number-Arithmetic-Operations".

## Usage
```cpp
#include <iostream>

#include "Base58.h"

int main() {
    std::string HexNumber = "002C710C62A461D225CE8B0E4B91708D6E58246D8404868BE8";
    std::string Base58Number = "";
    
    base58::HexToBase58(HexNumber,Base58Number);

    std::cout << Base58Number;
    // 153zABRVc13vJJzQD4iyBQh6cCeJiZZDNP
    return 0;
}
```

This is not a professional library. You are responsible for use.