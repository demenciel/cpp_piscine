
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
    {
      input += " ";
    }
  }

  clock_t startVector, endVector;
  double vectorTime;
  std::istringstream iss(input);
  try
  {
    startVector = clock();
    pm.createFordVector(iss);
    pm.sortVectorPairs();
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
  std::cout << "After: "; pm.printMergedVector();
  vectorTime = ((double) (endVector - startVector)) / CLOCKS_PER_SEC;
  std::cout << "Time to process a range of " << input.size() << " elements with std::vector : " << vectorTime << std::endl;

  return 0;
}
