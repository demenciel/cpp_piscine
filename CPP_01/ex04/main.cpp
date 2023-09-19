/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:05:49 by acouture          #+#    #+#             */
/*   Updated: 2023/09/19 18:09:50 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void createNewFile(std::string newContent, std::string fileName)
{
    std::string newName;
    // extracting the name of the file from the string
    std::string::size_type pos = fileName.find('.');
    if (pos != std::string::npos)
        newName = fileName.substr(0, pos);
    else
        newName = fileName;
    // writing the new content to the new file
    std::ofstream newFile(newName.append(".replace"));
    newFile << newContent << std::endl;

    newFile.close();
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return (-1);
    }
    std::string filename = av[1];
    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        std::cerr << "Could not open the file " << filename << std::endl;
        return 1;
    }
    std::string fileContent = transferContent(inputFile);
    inputFile.close();
    std::string replaceFile = replaceContent(fileContent, av[2], av[3]);
    createNewFile(replaceFile, filename);

    return (0);
}