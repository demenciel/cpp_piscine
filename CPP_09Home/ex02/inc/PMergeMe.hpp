#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <exception>
#include <ctime>

class PMergeMe
{
private:
    std::vector<std::vector<unsigned long> > fordVector;
    std::list<unsigned long> fordList;

public:
    PMergeMe();
    PMergeMe(PMergeMe const &copy);
    PMergeMe &operator=(PMergeMe const &rhs);
    ~PMergeMe();

    class NumberIsNotValidException : std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    // VECTOR
    void printFordVectorPairs() const;
    void printMergedVector();
    void createFordVector(std::istringstream &iss);
    void sortVectorPairs();
    std::vector<unsigned long> merge(const std::vector<unsigned long> &left,
                                               const std::vector<unsigned long> &right);
    void iterativeMergeSort();
    void createFordList(std::istringstream &is);
};

std::ostream &operator<<(std::ostream &out, std::vector<unsigned long> &vector);

#endif