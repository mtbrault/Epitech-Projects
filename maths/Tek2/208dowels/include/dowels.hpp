#ifndef DOWELS_H_
#define DOWELS_H_

#include <vector>

class   Dowels
{
public:
    Dowels(int, char **);
    ~Dowels();

    void    aff_table();
private:
    std::vector<int>    _values;
    std::vector<int>    _sumVal;
};

#endif

