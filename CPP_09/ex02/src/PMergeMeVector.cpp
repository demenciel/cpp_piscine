#include "../inc/PMergeMe.hpp"

int PMergeMe::executeVector(PMergeMe &pm, std::string input, int ac)
{
        clock_t startVector, endVector;
        double vectorTime;
        std::istringstream iss(input);
        try
        {
                startVector = clock();
                pm.createFordVector(iss);
                pm.iterativeMergeSort();
                endVector = clock();
        }
        catch (const PMergeMe::NumberIsNotValidException &e)
        {
                std::cerr << e.what() << std::endl;
                return 1;
        }
        std::cout << "Before: ";
        std::cout << input << std::endl;
        std::cout << "After: ";
        pm.printMergedVector();
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

void PMergeMe::sortVectorPairs()
{
        for (size_t i = 0; i < fordVector.size(); ++i)
        {
                if (fordVector[i].size() == 2 && fordVector[i][0] > fordVector[i][1])
                {
                        std::swap(fordVector[i][0], fordVector[i][1]);
                }
        }
}

std::vector<unsigned long> PMergeMe::merge(const std::vector<unsigned long> &left,
                                           const std::vector<unsigned long> &right)
{
        std::vector<unsigned long> result;
        size_t leftIndex = 0, rightIndex = 0;

        while (leftIndex < left.size() && rightIndex < right.size())
        {
                if (left[leftIndex] < right[rightIndex])
                {
                        result.push_back(left[leftIndex]);
                        leftIndex++;
                }
                else
                {
                        result.push_back(right[rightIndex]);
                        rightIndex++;
                }
        }
        while (leftIndex < left.size())
        {
                result.push_back(left[leftIndex]);
                leftIndex++;
        }
        while (rightIndex < right.size())
        {
                result.push_back(right[rightIndex]);
                rightIndex++;
        }
        return result;
}

void PMergeMe::insertElements(std::vector<unsigned long> &sortedSequence, const std::vector<unsigned long> &elementsToInsert)
{
        for (size_t i = 0; i < elementsToInsert.size(); ++i)
        {
                std::vector<unsigned long>::iterator position = std::lower_bound(sortedSequence.begin(), sortedSequence.end(), elementsToInsert[i]);
                sortedSequence.insert(position, elementsToInsert[i]);
        }
}

void PMergeMe::iterativeMergeSort()
{
        while (fordVector.size() > 1)
        {
                std::vector<std::vector<unsigned long> > tempVector;

                for (size_t i = 0; i < fordVector.size(); i += 2)
                {
                        if (i + 1 < fordVector.size())
                        {
                                std::vector<unsigned long> merged = merge(fordVector[i], fordVector[i + 1]);
                                tempVector.push_back(merged);
                        }
                        else
                                tempVector.push_back(fordVector[i]);
                }
                if (tempVector.size() > 1 && !tempVector.back().empty())
                {
                        std::vector<unsigned long> unmergedElements = tempVector.back();
                        tempVector.pop_back();
                        std::vector<unsigned long> &mergedSequence = tempVector.back();
                        insertElements(mergedSequence, unmergedElements);
                }
                fordVector = tempVector;
        }
}

bool PMergeMe::verifySortedSequence()
{
        for (size_t i = 0; i < fordVector.size() - 1; ++i)
        {
                if (fordVector[i][0] > fordVector[i + 1][0])
                        return false;
        }
        return true;
}
