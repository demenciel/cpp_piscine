#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>
#include <string>
#include <fstream>

#define CSV_PATH "/Users/acouture/Desktop/cpp_piscine/CPP_09Home/ex00/inc/data.csv"

class BitcoinExchange
{
private:

public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &copy);
    BitcoinExchange &operator=(BitcoinExchange const &rhs);
    ~BitcoinExchange();

    std::map<std::pair<int, std::string>, double> dbMap;
    std::map<std::string, double> csvMap;
    void print_map();
    void print_exchange();
};

std::string parseDate(std::string &line);
float parseRate(std::string &line);
std::map<std::string, double> parseCSV(const std::string& filename);
std::map<std::pair<int, std::string>, double> parseInputFile(const std::string &filename);

#endif