//
// EPITECH PROJECT, 2018
// 207demography
// File description:
// demograph method
//

#include <stdexcept>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include "demograph.hpp"

Demograph::Demograph(int ac, char **av)
    :xi(0), yi(0), x2(0), y2(0), xy(0)
{
    for (int i = 1; i < ac; i++) {
        _codeList.push_back(static_cast<std::string>(av[i]));
    }
}

Demograph::~Demograph()
{
}

std::vector<std::string>    Demograph::parsLine(std::string line)
{
    std::vector<std::string>    list;

    auto start = 0;
    auto end = line.find(';');
    while ("Antoine is an handsome man") {
        list.push_back(line.substr(start, end - start));
        if (end == std::string::npos)
            break ;
        start = end + 1;
        end = line.find(';', start);
    }
    return list;
}

void    Demograph::readFile(std::string country)
{
    std::ifstream               file("207demography_data.csv");
    std::string                 line;
    std::vector<std::string>    pars;
    std::vector<double>         val;
    int                         i = 0;
    bool                        find = false;

    if (!file)
        throw std::overflow_error("File not found");
    while (getline(file, line)) {
        pars = parsLine(line);
        if (pars[1] == country) {
            _countryList.push_back(pars[0]);
            find = true;
            for (auto &it : pars) {
		    if (i > 1) {
			    std::string add = it;
			    //add.replace(add.begin(), add.end(), ',', '.');
			    std::stringstream ss;
			    double tmp;
			    ss << add;
			    ss >> tmp;
			    _valList[i + 1959] += tmp;
		    }
                i++;
            }
        }
    }
    if (find == false)
        throw std::overflow_error(country + " doesn't exist");
    file.close();
}

void    Demograph::loadCountry()
{
    unsigned int size = 0;

    for (auto &it : _codeList)
        readFile(it);
    std::cout << "country: ";
    for (auto &it : _countryList) {
        std::cout << it;
        if (size < (_countryList.size() - 1))
            std::cout << ", ";
        size += 1;
    }
    std::cout << std::endl;
    for (auto &it : _valList) {
        xi += it.first;
        yi += it.second;
        x2 += pow(it.first, 2);
        y2 += pow(it.second, 2);
        xy += it.first * it.second;
    }
}

void    Demograph::calcFit1()
{
    double	b;
    double	a;
    double	sum = 0;
    
    std::cout << "fit 1" << std::endl;
    b = (_valList.size() * xy - xi * yi) / (_valList.size() * x2 - pow(xi, 2));
    a = ((1.0 / _valList.size()) * yi) - b * 1.0 / _valList.size() * xi;
    a /= 1000000;
    b /= 1000000;
    printf("\tY = %.2lf X ", b);
    printf((a < 0) ? "- " : "+ ");
    printf("%.2lf\n", (a < 0) ? a * -1 : a);
    for (auto &it : _valList)
	    sum += pow(it.second - ((b * (double)it.first + a) * 1000000), 2);
    printf("\tstandard deviation:\t%.2lf\n", sqrt(sum / _valList.size()) / 1000000);
    printf("\tpopulation in 2050:\t%.2lf\n", (b * 2050.0) + a);
}

void    Demograph::calcFit2()
{
    double  b;
    double  a;
    double  sum = 0;
    
    std::cout << "fit 2" << std::endl;
    b = (_valList.size() * xy - xi * yi) / (_valList.size() * y2 - pow(yi, 2));
    a = ((1.0 / _valList.size()) * xi) - b * 1.0 / _valList.size() * yi;
    b *= 1000000;
    printf("\tX = %.2lf Y ", b);
    printf((a < 0) ? "- " : "+ ");
    printf("%.2lf\n", (a < 0) ? a * -1 : a);
    for (auto &it : _valList)
	    sum += pow(it.second - (((it.first - a) / b) * 1000000), 2);
    printf("\tstandard deviation:\t%.2lf\n", sqrt(sum / _valList.size()) / 1000000);
    printf("\tpopulation in 2050:\t%.2lf\n", (2050.0 - a) / b);
}

void    Demograph::corelation()
{
    double  size = _valList.size();
    double  sub1 = size * x2 - pow(xi, 2);
    double  sub2 = size * y2 - pow(yi, 2);
    double  sup = size * xy - xi * yi;
    double  result = sup / sqrt(sub1 * sub2);
    
    printf("correlation: %.4lf\n", result);
}
