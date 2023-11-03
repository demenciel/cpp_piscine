/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:37:31 by acouture          #+#    #+#             */
/*   Updated: 2023/11/03 19:26:25 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Convert.hpp"

using std::cerr;
using std::cout;
using std::endl;
using std::string;


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: ./convert <literal>" << endl;
        return 1;
    }
    Convert convert;

    string literal = argv[1];
    if (convert.isChar(literal)) {
        convert.convertLiteral(literal);
    } else if (convert.isInt(literal)) {
        convert.convertLiteral(literal);
    } else if (convert.isFloat(literal)) {
        convert.convertLiteral(literal);
    } else if (convert.isDouble(literal)) {
        convert.convertLiteral(literal);
    } else {
        cout << "impossible" << endl;
    }
    return 0;
}