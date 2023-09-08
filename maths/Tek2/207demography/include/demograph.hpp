//
// EPITECH PROJECT, 2018
// 207demography
// File description:
// demograph class
//

#ifndef DEMOGRAPH_HPP_
# define DEMOGRAPH_HPP_

#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>

class Demograph
{
public:
    Demograph(int, char **);
    ~Demograph();  
    void    loadCountry();
    void    calcFit1();
    void    calcFit2();
    void    corelation();
    
private:
    void                        readFile(std::string);
    std::vector<std::string>    parsLine(std::string);
    std::map<int, double>       _valList;
    std::vector<std::string>    _codeList;
    std::vector<std::string>    _countryList;
    double                      xi;
    double                      yi;
    double                      x2;
    double                      y2;
    double                      xy;
};

#endif
