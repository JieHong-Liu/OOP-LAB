#include "password.h"
#include <iostream>
namespace
{
    std::string pw="";
    bool pw_is_valid(std::string pass)
    {
        int num_of_non_letter = 0;
        for (unsigned int i = 0; i < pass.length(); i++)
        {
            if ((pass[i] > 'a' && pass[i] < 'z') || (pass[i] > 'A' && pass[i] < 'Z'))
            {
                continue;
            }
            else
            {
                num_of_non_letter++;
            }
        }
        if (num_of_non_letter > 0 && pass.length() >=8)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
void Authenticate::inputPassword()
{
    while (!pw_is_valid(pw))
    {
        std::cout << "Enter your password (at least 8 characters and at least one non-letter)\n";
        std::cin >> pw;
    }
}
std::string Authenticate::getPassword()
{
    return pw;
}
