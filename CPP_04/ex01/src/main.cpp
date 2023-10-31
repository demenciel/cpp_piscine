/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:35:13 by acouture          #+#    #+#             */
/*   Updated: 2023/10/24 14:28:12 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

int main()
{
    int nb = 10;
    Animal *horde[nb];

    for (int i = 0; i < nb; ++i)
    {
        if (i % 2 == 0)
            horde[i] = new Dog();
        else
            horde[i] = new Cat();
        std::cout << horde[i]->getType() << std::endl;
        horde[i]->makeSound();
        std::cout << "------ C -----" << std::endl;
    }
    // delete animals
    for (int i = 0; i < nb; ++i)
    {
        delete horde[i];
        std::cout << "----- D -------" << std::endl;
    }

    std::cout << "----- Test Assignment -----" << std::endl;
    Dog *dog1 = new Dog();
    Dog *dog2 = new Dog();
    *dog1 = *dog2;
    std::cout << dog1->getType() << std::endl;
    std::cout << dog2->getType() << std::endl;
    dog1->makeSound();
    dog2->makeSound();
    delete dog1;
    delete dog2;

    std::cout << "----- Test Destruction -----" << std::endl;
    Animal *toDestroy = new Dog();
    delete toDestroy;
}
