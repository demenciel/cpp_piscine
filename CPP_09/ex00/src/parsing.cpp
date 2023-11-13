#include "../inc/BitcoinExchange.hpp"

std::string parseDate(std::string &line)
{
  std::string date;

  std::size_t dashPos = line.find('-');
  if (dashPos == std::string::npos)
    return ("Error: bad input => " + line.substr(0, line.find('|') + 1));

  int year = std::stoi(line.substr(0, dashPos));
  if (year < 2009 || year > 2023)
    return ("Error: bad input => " + line);

  std::size_t secondDashPos = line.find('-', dashPos + 1);
  if (secondDashPos == std::string::npos)
    return ("Error: wrong date format");

  int month = std::stoi(line.substr(dashPos + 1, secondDashPos - dashPos - 1));
  if (month < 1 || month > 12)
    return ("Error: bad input => " + line);

  int day = std::stoi(line.substr(secondDashPos + 1));
  if (day < 1 || day > 31)
    return ("Error: bad input => " + line);

  std::stringstream ss;
  ss << year << '-'
     << std::setfill('0') << std::setw(2) << month << '-'
     << std::setfill('0') << std::setw(2) << day;

  date = ss.str();

  return date;
}

float parseRate(std::string &line)
{
  float rate = -1.0f;

  try
  {
    rate = std::stof(line);
  }
  catch (const std::invalid_argument &e)
  {
    return -1.0f;
  }
  catch (const std::out_of_range &e)
  {
    return -1.0f;
  }

  if (rate < 0.0f)
    return -2.0f;
  else if (rate > 1000.0f)
    return -3.0f;

  return rate;
}

std::map<std::pair<int, std::string>, double> parseInputFile(const std::string &filename) {
    std::map<std::pair<int, std::string>, double> dbMap;
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Could not open the file " << filename << std::endl;
        return dbMap;
    }

    std::string line;
    int lineNumber = 0;
    while (std::getline(inputFile, line)) {
        ++lineNumber;
        std::string date = parseDate(line); 
        if (date.substr(0, 5).compare("Error") == 0) {
            dbMap.insert(std::make_pair(std::make_pair(lineNumber, date), -4.0f));
            continue;
        }
        std::string rateString = line.substr(line.find('|') + 1);
        double rate = parseRate(rateString);

        dbMap.insert(std::make_pair(std::make_pair(lineNumber, date), rate));
    }
    inputFile.close();
    return dbMap;
}

std::map<std::string, double> parseCSV(const std::string &filename)
{
        std::map<std::string, double> csvRates;
        std::ifstream file(filename);
        if (!file.is_open())
                return csvRates;
        std::string line;
        getline(file, line);

        while (getline(file, line))
        {
                std::stringstream linestream(line);
                std::string date;
                std::string rateStr;
                getline(linestream, date, ',');
                getline(linestream, rateStr);
                double rate = std::stod(rateStr);
                csvRates[date] = rate;
        }
        file.close();
        return csvRates;
}
