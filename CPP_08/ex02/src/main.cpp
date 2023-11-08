/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:43:48 by acouture          #+#    #+#             */
/*   Updated: 2023/11/08 14:06:46 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

int main()
{
    srand(time(0));
    std::cout << "\033[1;34m" << std::endl << "---------- SUBJECT MAIN ------------" << "\033[0m" << std::endl;
    Span span(5);
    try
    {
        span.addNumber(6);
        span.addNumber(3);
        span.addNumber(17);
        span.addNumber(9);
        span.addNumber(11);

        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
    }
    catch (const Span::SpanIsFullException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\033[1;34m" << std::endl << "---------- RANDOM 500000 LOOP ------------" << "\033[0m" << std::endl;
    Span span3(500000);
    try
    {
        for (int i = 0; i < 500000; ++i)
        {
            unsigned int num = (rand() % 5000000) + 1;
            span3.addNumber(num);
        }

        // std::cout << span3;
        std::cout << "Shortest span: " << span3.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span3.longestSpan() << std::endl;
    }
    catch (const Span::SpanIsFullException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\033[1;34m" << std::endl << "---------- RANDOM 10000 LOOP ------------" << "\033[0m" << std::endl;
    Span span4(10000);
    try
    {
        for (int i = 0; i < 10000; ++i)
        {
            unsigned int num = (rand() % 100000) + 1;
            span4.addNumber(num);
        }

        std::cout << "Shortest span: " << span4.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span4.longestSpan() << std::endl;
    }
    catch (const Span::SpanIsFullException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\033[1;34m" << std::endl << "---------- FILL RANGE ------------" << "\033[0m" << std::endl;
    unsigned int fillNumber = 10000;
    Span span5(fillNumber);
    try
    {

        std::vector<unsigned int> numbers(fillNumber);
        std::iota(numbers.begin(), numbers.end(), 0);

        span5.addRange(numbers.begin(), numbers.end());
        // std::cout << span5;
        std::cout << "Shortest span: " << span5.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span5.longestSpan() << std::endl;
    }
    catch (const Span::SpanIsFullException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "\033[1;31m" << std::endl << "---------- FAIL FILL ------------" << "\033[0m" << std::endl;
    Span span2(10);
    try
    {
        for (int i = 0; i < 12; ++i)
            span2.addNumber(i);

        std::cout << "Shortest span: " << span2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span2.longestSpan() << std::endl;
    }
    catch (const Span::SpanIsFullException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\033[1;31m" << std::endl << "---------- CLEAN UP ------------" << "\033[0m" << std::endl;
    return 0;
}