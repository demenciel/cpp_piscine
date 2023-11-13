
#include "../inc/BitcoinExchange.hpp"

int main(int ac, char **av)
{
  BitcoinExchange exchange;

  if (ac != 2)
  {
    std::cout << "Usage: ./bitcoin [file]" << std::endl;
    return 1;
  }
  std::string filename = av[1];

  exchange.dbMap = parseInputFile(filename);
  exchange.csvMap = parseCSV(CSV_PATH);
  if (exchange.csvMap.empty())
  {
    std::cout << "Error: Opening CSV Failed" << std::endl;
    return 1;
  }

  exchange.print_exchange();

  return 0;
}