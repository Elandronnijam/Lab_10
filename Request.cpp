#include <iostream>

#include <string>

#include "Header.h"

int request()
{

    //6JIOK Bbl6OPA BAPUAHTA

    int VariantNomber = 0, EmergencyStop = 0;
    std::cout << "Choose the variant: 16 or 17: ";
    std::cin >> VariantNomber;
    std::cout << std::endl;
    if (VariantNomber == 16)
    {
        EmergencyStop = EmergencyStop + 1;
        std::cout << "Starting 16 variant " << std::endl << std::endl;
        variant16();
    }
    if (VariantNomber == 17)
    {
        EmergencyStop = EmergencyStop + 1;
        std::cout << "Starting 17 variant " << std::endl << std::endl;
        variant17();
    }

    //6JIOK ABAPUUHrO BbIXODA

    if (EmergencyStop != 1)
    {
        std::cout << "Something went wrong! The programm was emergency stopped!" << std::endl;
        std::cout << "Error code: ES != 1" << std::endl;
        return 0;
    }

    //6JIOK IIEPE3AIIYCKA

    int restart_request = 0;
    std::cout << "Enter 1 to restart, any other number to close: ";
    std::cin >> restart_request;
    if (restart_request == 1)
    {
        std::cout << std::endl << "loading..." << std::endl << std::endl;
    }
    return restart_request;
}