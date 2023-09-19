/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:02:21 by acouture          #+#    #+#             */
/*   Updated: 2023/09/19 18:09:29 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

std::string replaceContent(std::string file, std::string find, std::string replace);
std::string transferContent(std::ifstream &inputFile);

#endif