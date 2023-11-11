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

void PMergeMe::printFordList() const
{
    std::list<std::pair<unsigned long, unsigned long> >::const_iterator it;
    for (it = fordList.begin(); it != fordList.end(); ++it)
    {
        std::cout << it->first << " ";
        if (it->second != ULONG_MAX)
        {
            std::cout << it->second << " ";
        }
    }
    std::cout << std::endl;
}

void PMergeMe::printFinalList()
{
    std::list<unsigned long>::iterator it;
    for (it = finalList.begin(); it != finalList.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

std::list<unsigned long> PMergeMe::createWorkingList()
{
    std::list<unsigned long> workingList;

    for (std::list<std::pair<unsigned long, unsigned long> >::iterator it = fordList.begin(); it != fordList.end(); ++it)
        workingList.push_back(it->first);
    workingList.sort();
    return workingList;
}

void PMergeMe::fordJonhson()
{
    std::list<unsigned long> workingList = createWorkingList();
    std::list<unsigned long> mergedList;

    for (std::list<unsigned long>::iterator wlIt = workingList.begin(); wlIt != workingList.end(); ++wlIt)
    {
        for (std::list<std::pair<unsigned long, unsigned long> >::iterator flIt = fordList.begin(); flIt != fordList.end(); ++flIt)
        {
            if (flIt->first == *wlIt || flIt->second == *wlIt)
            {
                insertInOrder(mergedList, flIt->first);
                insertInOrder(mergedList, flIt->second);
                fordList.erase(flIt);
                break;
            }
        }
    }
    finalList = mergedList;
}

void PMergeMe::insertInOrder(std::list<unsigned long> &list, unsigned long num)
{
    std::list<unsigned long>::iterator it = list.begin();
    while (it != list.end() && *it < num)
    {
        ++it;
    }
    list.insert(it, num);
}

bool PMergeMe::verifySortedList()
{
    std::list<unsigned long>::iterator it = finalList.begin();
    std::list<unsigned long>::iterator it2 = finalList.begin();
    ++it2;
    while (it2 != finalList.end())
    {
        if (*it > *it2)
            return false;
        ++it;
        ++it2;
    }
    return true;
}

int PMergeMe::executeList(PMergeMe &pm, std::string input, int ac)
{
    clock_t start, end;
    double time;
    std::istringstream iss2(input);
    try
    {
        start = clock();
        pm.createFordList(iss2);
        pm.fordJonhson();
        // pm.printFinalList();
        end = clock();
    }
    catch (const PMergeMe::NumberIsNotValidException &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << (ac - 1) << " elements with std::list : " << time << std::endl;
    if (pm.verifySortedList())
        std::cout << "\033[1;32m"
                  << "---------- LIST IS SORTED ------------"
                  << "\033[0m" << std::endl;
    else
        std::cout << "\033[1;34m"
                  << "---------- LIST IS NOT SORTED ------------"
                  << "\033[0m" << std::endl;
    std::cout << std::endl;
    return 0;
};
