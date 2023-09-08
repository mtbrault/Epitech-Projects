#include <iostream>
#include "dowels.hpp"

Dowels::Dowels(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
        _values.push_back(atoi(av[i]));
}

Dowels::~Dowels()
{
}

void    Dowels::aff_table()
{
    int before;
    int sum;
    int total = 0;

    std::cout << "  x  |  ";
    for (int i = 0; i < (int)_values.size(); i++) {
        before = i;
        sum = _values[i];
        while (sum < 10 && i < (int)_values.size()) {
            i += 1;
            sum += _values[i];
        }
        _sumVal.push_back(sum);
        if (before == i)
            std::cout << i << "  |  ";
        else if ((i + 1) >= (int)_values.size())
            std::cout << before << "+  |  ";
        else
            std::cout << before << "-" << i << "  |  ";
    }
    std::cout << "total" << std::endl << " Ox  |  ";
    for (auto &it : _sumVal) {
        std::cout << it << "  |  ";
        total += it;
    }
    std::cout << total << std::endl;
}