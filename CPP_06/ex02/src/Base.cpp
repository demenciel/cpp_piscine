/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:27:49 by acouture          #+#    #+#             */
/*   Updated: 2023/11/04 15:45:37 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base::~Base() 
{
    std::cout << "Base destructor called" << std::endl;
};

// the dynamic cast is specifically used for polymorphism, when a base class points to a derived class
// the dynamic cast checks both at run time and compilation time
void Base::identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "Pointer is of type: A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Pointer is of type: B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Pointer is of type: C" << std::endl;
}

void Base::identify(Base &p)
{
    if (dynamic_cast<A *>(&p))
        std::cout << "Is a reference to type: A" << std::endl;
    else if (dynamic_cast<B *>(&p))
        std::cout << "Is a reference to type: B" << std::endl;
    else if (dynamic_cast<C *>(&p))
        std::cout << "Is a reference to type: C" << std::endl;
}

Base* Base::generate() {
    int i = rand() % 3;
    if (i == 0)
        return (new A());
    else if (i == 1)
        return (new B());
    else
        return (new C());
}