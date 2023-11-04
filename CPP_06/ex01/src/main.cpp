/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:37:31 by acouture          #+#    #+#             */
/*   Updated: 2023/11/04 14:03:27 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Data.hpp"
#include <iostream>

int main() {
    Data myData;
    Data myData2;

    Data* ptr = &myData;
    std::cout << "Original Data pointer myData: " << ptr << std::endl;

    ptr = &myData2;
    std::cout << "Changing pointer to myData2: " << ptr << std::endl;
    
    uintptr_t serialized = serialize(ptr);
    std::cout << "Serialized Data pointer: " << serialized << std::endl;

    Data* deserialized = deserialize(serialized);
    std::cout << "Deserialized Data pointer: " << deserialized << std::endl;

    if (ptr == deserialized) {
        std::cout << "Success: Original and deserialized pointers are the same." << std::endl;
    } else {
        std::cout << "Error: Pointers do not match." << std::endl;
    }

    return 0;
}
