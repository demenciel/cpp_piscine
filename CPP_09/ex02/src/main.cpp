
#include "../inc/PMergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return 1;
    }

    PMergeMe pm;
    std::string input;
    for (int i = 1; i < ac; ++i)
    {
        input += av[i];
        if (i < ac - 1)
            input += " ";
    }

    if (pm.executeVector(pm, input, ac) == -1)
        return -1;

    std::cout << "---------- LIST ---------" << std::endl;
    std::istringstream iss2(input);
    pm.createFordList(iss2);
    std::list<unsigned long> workingList = pm.createWorkingList();
    // pm.iterativeMergeSortList();
    pm.printFordList();
    return 0;
}

