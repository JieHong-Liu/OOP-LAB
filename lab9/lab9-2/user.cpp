#include "user.h"
#include <iostream>
namespace
{
    std::string name = "";
    bool is_valid(std::string user_name)
    {
        int num_of_letter = 0;
        std::cout << "user_name's length is " << user_name.length() << std::endl;
        for (int i = 0; i < user_name.length(); i++)
        {
            if ((user_name[i] >= 'a' && user_name[i] <= 'z') || (user_name[i] >= 'A' && user_name[i] <= 'Z'))
            {
                num_of_letter++;
            }
        }
        if (num_of_letter == 8 && user_name.length() == 8)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
void Authenticate::inputUserName()
{

    while (!is_valid(name))
    {
        std::cout << "Enter your username (8 letters only)\n";
        std::cin >> name;
    }
}
std::string Authenticate::getUserName()
{
    return name;
}
