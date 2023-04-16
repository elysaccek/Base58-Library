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