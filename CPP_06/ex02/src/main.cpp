/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:35:28 by acouture          #+#    #+#             */
/*   Updated: 2023/11/04 15:47:15 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

int main () 
{
    srand(static_cast<unsigned int>(time(nullptr)));
    
    Base *base = new Base();
    Base *a = new A();
    Base *b = new B();
    Base *c = new C();

    std::cout << "---------- POINTER IDENTIFY -----------" << std::endl << std::endl;
    base->identify(a);
    base->identify(b);
    base->identify(c);

    std::cout << "--------- REFERENCE IDENTIFY ---------" << std::endl << std::endl;
    base->identify(*a);
    base->identify(*b);
    base->identify(*c);

    std::cout << "---------- GENERATE RANDOMS -----------" << std::endl << std::endl;
    Base *ptr = base->generate();
    Base *ptr2 = base->generate();
    Base *ptr3 = base->generate();
    Base *ptr4 = base->generate();
    Base *ptr5 = base->generate();
    Base *ptr6 = base->generate();

    std::cout << "---------- POINTER IDENTIFY -----------" << std::endl << std::endl;
    base->identify(ptr);
    base->identify(ptr2);
    base->identify(ptr3);
    base->identify(ptr4);
    base->identify(ptr5);
    base->identify(ptr6);

    std::cout << "--------- CLEAN ------------" << std::endl << std::endl;
    delete base;
    delete a;
    delete b;
    delete c;
    delete ptr;
    delete ptr2;
    delete ptr3;
    delete ptr4;
    delete ptr5;
    delete ptr6;
    return (0);
}