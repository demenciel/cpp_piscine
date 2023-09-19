/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:09:38 by acouture          #+#    #+#             */
/*   Updated: 2023/09/19 18:09:43 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

std::string transferContent(std::ifstream &inputFile)
{
    std::stringstream buffer;

    buffer << inputFile.rdbuf();
    std::string fileContent = buffer.str();
    return (fileContent);
}

std::string replaceContent(std::string file, std::string find, std::string replace)
{
    size_t pos = file.find(find);

    while (pos != std::string::npos)
    {
        file.erase(pos, find.length());
        file.insert(pos, replace);
        pos = file.find(find, pos + replace.length());
    }
    return file;
}