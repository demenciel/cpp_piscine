#include "../inc/PMergeMe.hpp"

int PMergeMe::executeVector(PMergeMe &pm, std::string input, int ac)
{
        clock_t startVector, endVector;
        double vectorTime;
        std::istringstream iss(input);
        int isEmpty = iss.rdbuf()->in_avail();
        if (isEmpty == 0)
                return -2;
        try
        {
                startVector = clock();
                pm.createFordVector(iss);
                pm.printFordVectorPairs();
                pm.vectorFordJonhson();
                endVector = clock();
        }
        catch (const PMergeMe::NumberIsNotValidException &e)
        {
                std::cerr << e.what() << std::endl;
                return 1;
        }
        vectorTime = ((double)(endVector - startVector)) / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of " << (ac - 1) << " elements with std::vector : " << vectorTime;
        if (pm.verifySortedSequence())
                std::cout << "\033[1;32m" << std::endl
                          << "---------- VECTOR IS SORTED ------------"
                          << "\033[0m" << std::endl;
        else
                std::cout << "\033[1;34m" << std::endl
                          << "---------- VECTOR IS NOT SORTED ------------"
                          << "\033[0m" << std::endl;
        std::cout << std::endl;
        return 0;
};

void PMergeMe::printFordVectorPairs() const
{
        for (std::vector<std::vector<unsigned long> >::const_iterator it = fordVector.begin(); it != fordVector.end(); ++it)
        {
                if (it->size() == 2)
                        std::cout << "(" << (*it)[0] << ", " << (*it)[1] << ") ";
                else if (!it->empty())
                        std::cout << "(" << (*it)[0] << ") ";
        }
        std::cout << std::endl;
};

std::ostream &operator<<(std::ostream &out, std::vector<unsigned long> &vector)
{
        for (std::vector<unsigned long>::iterator it = vector.begin(); it != vector.end(); ++it)
                out << *it << " ";
        return out;
}

void PMergeMe::printMergedVector()
{
        for (std::vector<std::vector<unsigned long> >::iterator it = fordVector.begin(); it != fordVector.end(); ++it)
        {
                std::cout << *it << std::endl;
        }
        std::cout << std::endl;
};

void PMergeMe::createFordVector(std::istringstream &iss)
{
        std::string token;
        unsigned long num;
        std::vector<unsigned long> subVector;

        while (iss >> token)
        {
                try
                {
                        if (token.at(0) == '-')
                                throw NumberIsNotValidException();
                        num = std::stoul(token);
                        subVector.push_back(num);
                        if (subVector.size() == 2)
                        {
                                if (subVector.size() == 2 && subVector[0] > subVector[1])
                                        std::swap(subVector[0], subVector[1]);
                                this->fordVector.push_back(subVector);
                                subVector.clear();
                        }
                }
                catch (...)
                {
                        throw NumberIsNotValidException();
                }
        }
        if (!subVector.empty())
        {
                this->fordVector.push_back(subVector);
        }
}

void PMergeMe::insertInOrderVector(std::vector<unsigned long> &vector, unsigned long num) {
    std::vector<unsigned long>::iterator it;
    for (it = vector.begin(); it != vector.end(); ++it) {
        if (*it > num) {
            vector.insert(it, num);
            return;
        }
    }
        vector.push_back(num);
}

std::vector<unsigned long> PMergeMe::createWorkingVector()
{
        std::vector<unsigned long> workingVector;
        std::vector<std::vector<unsigned long> >::iterator it;
        for (it = fordVector.begin(); it != fordVector.end(); ++it)
        {
                if (it->size() == 2)
                        workingVector.push_back((*it)[0]);
                else if (!it->empty())
                        workingVector.push_back((*it)[0]);
        }
        return workingVector;
}

void    PMergeMe::vectorFordJonhson()
{
        std::vector<unsigned long> workingVector = createWorkingVector();
        std::sort(workingVector.begin(), workingVector.end());
        std::vector<unsigned long> vector;

        for (std::vector<unsigned long>::iterator itWV = workingVector.begin(); itWV != workingVector.end(); ++itWV) {
                for (std::vector<std::vector<unsigned long> >::iterator itFV = fordVector.begin(); itFV != fordVector.end(); ++itFV) {
                        if (!itFV->empty() && (itFV->at(0) == *itWV || (itFV->size() == 2 && itFV->at(1) == *itWV))) {
                                insertInOrderVector(vector, itFV->at(0));
                                if (itFV->size() == 2) {
                                        insertInOrderVector(vector, itFV->at(1));
                                }
                                break;
                        }
                }
        }
        mergedVector = vector;
}

bool PMergeMe::verifySortedSequence()
{
        for (size_t i = 0; i < mergedVector.size() - 1; ++i)
        {
                if (mergedVector[i] > mergedVector[i + 1])
                        return false;
        }
        return true;
}
