#include <iostream>
#include <Windows.h>

// This key is used for encryption and it is not the final DCM SecurityAccess Key
#define GENERATION_KEY 0x2202;

// Encryption function
uint16_t generateSecurityAccessKey(uint16_t seed)
{
    return seed ^ GENERATION_KEY;
}

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    std::cin.unsetf(std::ios::dec);
    std::cin.unsetf(std::ios::hex);
    std::cin.unsetf(std::ios::oct);

    uint16_t seed;

    std::cout << "This is a key generator for DCM SecurityAccess (0x27) service implemented on GoKart" << std::endl << std::endl;
    std::cout << "Enter the seed (in hex): ";
    std::cin >> std::hex >> seed >> std::dec;

    std::cout << "Seed: 0x" << std::hex << seed << std::dec << std::endl;
    SetConsoleTextAttribute(hConsole, 2);
    std::cout << "Key: 0x" << std::hex << generateSecurityAccessKey(seed) << std::dec << std::endl;

    SetConsoleTextAttribute(hConsole, 15);

    return 0;
}
