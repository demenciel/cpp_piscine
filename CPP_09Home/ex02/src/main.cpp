
#include "../inc/PMergeMe.hpp"

int main(int ac, char **av)
{
  if (ac < 2)
  {
    std::cerr << "Error: Invalid number of arguments" << std::endl;
    return 1;
  }

  clock_t startVector, endVector;
  double timeSortVector;
  PMergeMe pm;
  std::string input;

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

  size_t numberOfAv = 0;
  std::cout << "Before: ";
  for (int i = 1; i < ac; ++i)
  {
    input += av[i];
    if (i < ac - 1)
    {
      input += " ";
      numberOfAv++;
      std::cout << input;
    }
  }
  std::cout << std::endl;
  std::cout << "After: ";
  pm.printMergedVector();

  timeSortVector = ((double)(endVector - startVector)) / CLOCKS_PER_SEC;
  std::cout << "Time to process a range of " << numberOfAv << " elements with std::vector : " << timeSortVector << std::endl;

  return 0;
}
