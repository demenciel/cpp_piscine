#include "../inc/BitcoinExchange.hpp"
using std::cin;
using std::cout;
using std::endl;
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
        *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
        if (&rhs != this)
        {
                return *this;
        }
        return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::print_map()
{
        for (std::map<std::pair<int, std::string>, double>::iterator it = dbMap.begin(); it != dbMap.end(); ++it)
        {
                const std::pair<int, std::string> &key = it->first;
                double rate = it->second;
                const std::string &date = key.second;

                if (rate == -2.0f)
                        std::cerr << "Error: not a positive number." << std::endl;
                else if (rate == -3.0f)
                        std::cerr << "Error: too large a number." << std::endl;
                else if (rate == -1.0f)
                        std::cerr << "Error: wrong format for date " << date << std::endl;
                else
                {
                        if (date.substr(0, 5) == "Error")
                                std::cerr << date << std::endl;
                        else
                                std::cout << date << " => " << rate << std::endl;
                }
        }
}

void BitcoinExchange::print_exchange()
{
        for (std::map<std::pair<int, std::string>, double>::const_iterator it = this->dbMap.begin(); it != this->dbMap.end(); ++it)
        {
                const std::pair<int, std::string> &key = it->first;
                const std::string &date = key.second;
                double rate = it->second;

                if (rate == -4.0f)
                        std::cerr << date << std::endl;
                else if (rate == -2.0f)
                        std::cerr << "Error: not a positive number." << std::endl;
                else if (rate == -3.0f)
                        std::cerr << "Error: too large a number." << std::endl;
                else if (rate == -1.0f)
                        std::cerr << "Error: wrong format for date " << date << std::endl;
                else
                {
                        std::map<std::string, double>::const_iterator csvRateIt = this->csvMap.find(date);
                        csvRateIt = this->csvMap.lower_bound(date);
                        if ((csvRateIt != this->csvMap.begin() && csvRateIt == this->csvMap.end()) || csvRateIt->first > date)
                                --csvRateIt;

                        double csvRate = csvRateIt->second;
                        double multipliedRate = rate * csvRate;
                        std::cout << date << " => " << rate << " = " << multipliedRate << std::endl;
                }
        }
}
