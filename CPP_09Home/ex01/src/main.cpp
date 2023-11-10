
#include "../inc/RPN.hpp"

int main(int ac, char **av)
{

  if (ac != 2)
  {
    std::cerr << "Usage: ./RPN <expression>" << std::endl;
    return 1;
  }
  RPN rpn;
  std::stack<double> stack;

  stack = rpn.RPNstack;
  std::string input = av[1];

  std::istringstream is(input);
  std::string firstToken;
  int operatorCount = 0;
  
  while (is >> firstToken)
  {
    if (rpn.isOperator(firstToken))
      operatorCount++;
  }
  if (operatorCount == 0)
  {
    std::cerr << "Error: No operators" << std::endl;
    return 1;
  }

  std::istringstream iss(input);
  std::string token;
  while (iss >> token)
  {
    if (rpn.isNumber(token))
      stack.push(std::stod(token));
    else if (rpn.isOperator(token))
    {
      if (stack.size() < 2)
      {
        std::cerr << "Error: Insufficient operands for " << token << std::endl;
        return 1;
      }

      double number2 = stack.top();
      stack.pop();
      double number1 = stack.top();
      stack.pop();
      double result;

      result = rpn.makeOperation(number1, number2, token);
      if (result == INT16_MIN)
        return 1;
      stack.push(result);
    }
    else
    {
      std::cerr << "Error: Invalid token '" << token << "'" << std::endl;
      return 1;
    }
  }
  std::cout << "Result: " << stack.top() << std::endl;
}
