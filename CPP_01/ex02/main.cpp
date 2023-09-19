/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:05:49 by acouture          #+#    #+#             */
/*   Updated: 2023/09/18 17:13:01 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"

int main() {
    std::string string = "HI THIS IS BRAIN";
    std::string *strPTR = &string;
    std::string &strREF = string;

    std::cout << "string Address: " << &string << std::endl;
    std::cout << "strPTR Address: " << strPTR << std::endl;
    std::cout << "strREF Address: " << &strREF << std::endl;

    std::cout << "Value of myString: " << string << std::endl;
    std::cout << "Value of stringPTR: " << *strPTR << std::endl;
    std::cout << "Value of stringREF: " << strREF << std::endl;
}