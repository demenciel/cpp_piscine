
#include "Fixed.hpp"

// PDF MAIN
// int main(void)
// {
//     Fixed a;
//     Fixed const b(Fixed(5.05f) * Fixed(2));
//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max(a, b) << std::endl;
//     return 0;
// }

// ----------- incrementation/decrementation
// int main(void)
// {
//     Fixed a(42);

//     std::cout << "a before prefix incrementation: " << a.toFloat() << std::endl;
//     std::cout << "a after prefix incrementation: " << (++a).toFloat() << std::endl;
//     a = Fixed(42);
//     std::cout << "a before postfix incrementation: " << a << std::endl;
//     std::cout << "a after postfix incrementation: " << (a++) << std::endl;

//     return 0;
// }

// ----------- arithmetics
// int main()
// {
//     Fixed a(10);
//     Fixed b(20);
//     Fixed g(0);
//     Fixed c = a + b;
//     Fixed d = a - b;
//     Fixed e = a * b;
//     Fixed f = g / a;

//     std::cout << "a + b = " << c.toFloat() << std::endl;
//     std::cout << "a - b = " << d.toFloat() << std::endl;
//     std::cout << "a * b = " << e.toFloat() << std::endl;
//     std::cout << "a / b = " << f.toFloat() << std::endl;
// }

// ----------- comparaison
// int main()
// {
//     Fixed a(10);
//     Fixed b(20);

//     std::cout << "a(10) > b(20) = " << (a > b) << std::endl;
//     std::cout << "a(10) < b(20) = " << (a < b) << std::endl;
//     std::cout << "a(10) >= b(20) = " << (a >= b) << std::endl;
//     std::cout << "a(10) <= b(20) = " << (a <= b) << std::endl;
//     std::cout << "a(10) == b(20) = " << (a == b) << std::endl;
//     std::cout << "a(10) != b(20) = " << (a != b) << std::endl;
// }

// ----------- return comparaison
// int main()
// {
//     Fixed a(10.12f);
//     Fixed b(20.12f);
//     const Fixed c(16.1166f);
//     const Fixed d(212.11f);

//     Fixed &smallest = Fixed::min(a, b);
//     std::cout << "The smallest value is: " << smallest.toFloat() << std::endl;
//     Fixed &biggest = Fixed::max(a, b);
//     std::cout << "The biggest value is: " << biggest.toFloat() << std::endl;
//     const Fixed &smallestConst = Fixed::min(c, d);
//     std::cout << "The smallest const value is: " << smallestConst.toFloat() << std::endl;
//     const Fixed &biggestConst = Fixed::max(c, d);
//     std::cout << "The biggest const value is: " << biggestConst.toFloat() << std::endl;
// }