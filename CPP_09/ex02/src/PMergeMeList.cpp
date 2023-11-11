#include "../inc/PMergeMe.hpp"

void PMergeMe::createFordList(std::istringstream &is)
{
    std::string token;
    unsigned long num1, num2;

    while (is >> token)
    {
        try
        {
            if (token.at(0) == '-')
                throw NumberIsNotValidException();
            num1 = std::stoul(token);

            if (!(is >> token))
            {
                fordList.push_back(std::make_pair(num1, ULONG_MAX));
                break;
            }

            if (token.at(0) == '-')
                throw NumberIsNotValidException();
            num2 = std::stoul(token);
            if (num1 > num2)
                std::swap(num1, num2);
            fordList.push_back(std::make_pair(num1, num2));
        }
        catch (...)
        {
            throw NumberIsNotValidException();
        }
    }
}

void PMergeMe::printFordList() const {
    std::list<std::pair<unsigned long, unsigned long> >::const_iterator it;
    for (it = fordList.begin(); it != fordList.end(); ++it) {
        std::cout << it->first << " ";
        if (it->second != ULONG_MAX) {
            std::cout << it->second << " ";
        }
    }
    std::cout << std::endl;
}

std::list<std::pair<unsigned long, unsigned long> > PMergeMe::merge(const std::list<std::pair<unsigned long, unsigned long> > &left,
                                                                   const std::list<std::pair<unsigned long, unsigned long> > &right)
{
    std::list<std::pair<unsigned long, unsigned long> > result;
    std::list<std::pair<unsigned long, unsigned long> >::const_iterator itLeft = left.begin();
    std::list<std::pair<unsigned long, unsigned long> >::const_iterator itRight = right.begin();

    while (itLeft != left.end() && itRight != right.end())
    {
        if (itLeft->first < itRight->first)
        {
            result.push_back(*itLeft);
            ++itLeft;
        }
        else if (itLeft->first > itRight->first)
        {
            result.push_back(*itRight);
            ++itRight;
        }
        else
        {
            if (itLeft->second < itRight->second)
            {
                result.push_back(*itLeft);
                ++itLeft;
            }
            else
            {
                result.push_back(*itRight);
                ++itRight;
            }
        }
    }
    while (itLeft != left.end())
    {
        result.push_back(*itLeft);
        ++itLeft;
    }
    while (itRight != right.end())
    {
        result.push_back(*itRight);
        ++itRight;
    }
    return result;
}

std::list<unsigned long> PMergeMe::createWorkingList()
{
    std::list<unsigned long> workingList;

    for (std::list<std::pair<unsigned long, unsigned long> >::iterator it = fordList.begin(); it != fordList.end(); ++it)
        workingList.push_back(it->first);
    workingList.sort();

    for (std::list<unsigned long>::iterator it = workingList.begin(); it != workingList.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    return workingList;
}

void    PMergeMe::fordJonhson()
{
    std::list<std::pair<unsigned long, unsigned long> >::iterator itFord = fordList.begin();
    std::list<std::pair<unsigned long, unsigned long> >::iterator iteFord = fordList.end();

    
}
