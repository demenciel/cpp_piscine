/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:35:13 by acouture          #+#    #+#             */
/*   Updated: 2023/10/19 17:03:32 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

int main()
{
    // ------- SUBJECT MAIN TEST
    // const Animal *meta = new Animal();
    // const Animal *j = new Dog();
    // const Animal *i = new Cat();
    // std::cout << "-------------" << std::endl;

    // std::cout << j->getType() << " " << std::endl;
    // j->makeSound();
    // std::cout << "-------------" << std::endl;

    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound();
    // std::cout << "-------------" << std::endl;

    // meta->makeSound();
    // delete meta;
    // delete i;
    // delete j;

    // ------ WRONG ANIMAL TEST
    const WrongAnimal *meta = new WrongAnimal();
    const Animal *j = new Dog();
    const WrongAnimal *i = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
    delete j;

    // --------- ARRAY POINTERS TEST
    // const Animal* animals[3];

    // animals[0] = new Animal();
    // animals[1] = new Dog();
    // animals[2] = new Cat();

    // for (int i = 0; i < 3; ++i) {
    //     std::cout << animals[i]->getType() << " ";
    //     animals[i]->makeSound();
    // }

    // for (int i = 0; i < 3; ++i) {
    //     delete animals[i];
    // }
    
    // --------- ASSIGNMENT AND COPY TESTS
    // Animal a1;
    // Animal a2 = a1; // Copy constructor
    // Animal a3;
    // a3 = a1; // Assignment operator

    // std::cout << a1.getType() << " ";
    // a1.makeSound();

    // std::cout << a2.getType() << " ";
    // a2.makeSound();

    // std::cout << a3.getType() << " ";
    // a3.makeSound();
}
