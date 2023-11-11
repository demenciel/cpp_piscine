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
#include <utility>

class PMergeMe
{
private:
    std::vector<std::vector<unsigned long> > fordVector;
    std::vector<unsigned long> mergedVector;
    std::list<std::pair<unsigned long, unsigned long> > fordList;
    std::list<unsigned long> finalList;

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
    int  executeVector(PMergeMe & pm, std::string input, int ac);
    void printFordVectorPairs() const;
    void printMergedVector();
    void vectorFordJonhson();
    void createFordVector(std::istringstream &iss);
    void sortVectorPairs();
    std::vector<unsigned long> createWorkingVector();
    void insertInOrderVector(std::vector<unsigned long> &vector, unsigned long num);
    bool verifySortedSequence();

    // LIST
    void createFordList(std::istringstream &is);
    void printFordList() const;
    std::list<std::pair<unsigned long, unsigned long> > merge(const std::list<std::pair<unsigned long, unsigned long> > &left,
                                                              const std::list<std::pair<unsigned long, unsigned long> > &right);
    std::list<unsigned long> createWorkingList();
    void fordJonhson();
    void printFinalList();
    void insertInOrder(std::list<unsigned long> &list, unsigned long num);
    bool verifySortedList();
    int executeList(PMergeMe &pm, std::string input, int ac);

};

std::ostream &operator<<(std::ostream &out, std::vector<unsigned long> &vector);
std::ostream &operator<<(std::ostream &out, std::list<unsigned long> &list);

#endif