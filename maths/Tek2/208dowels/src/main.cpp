#include <iostream>
#include "dowels.hpp"

int check_is_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 10) {
        std::cerr << "Invalid number of arguments" << std::endl;
        return 84;
    }
    for (int i = 1; i < ac; i++) {
        if (check_is_number(av[i]) == 1) {
            std::cerr << "Please only select integer arguments" << std::endl;
            return 84;
        }
    }
    Dowels  dowels(ac, av);
    dowels.aff_table();
    return 0;
}