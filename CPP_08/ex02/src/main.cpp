/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:43:48 by acouture          #+#    #+#             */
/*   Updated: 2023/11/08 15:55:30 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"

int main()
{
    std::cout << " ------------- MUTANT STACK TEST ------------- " << std::endl;

    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator itstack = mstack.begin();
    MutantStack<int>::iterator itestack = mstack.end();
    ++itstack;
    --itstack;
    while (itstack != itestack)
    {
        std::cout << *itstack << std::endl;
        ++itstack;
    }
    std::stack<int> s(mstack);
    
    std::cout << " ------------- LIST TEST ------------- " << std::endl;
    std::list<int> list;
    
    list.push_front(5);
    list.push_front(17);
    std::cout << list.front() << std::endl;
     list.pop_front();
    std::cout << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    //[...]
    list.push_back(0);
    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ite = list.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << " ------------- VECTOR TEST ------------- " << std::endl;
    std::vector<int> vector;
    
    vector.insert(vector.begin(), 5);
    vector.insert(vector.begin(), 17);
    std::cout << vector.front() << std::endl;
    vector.pop_back();
    std::cout << vector.size() << std::endl;
    vector.insert(vector.end(), 3);
    vector.insert(vector.end(), 5);
    vector.insert(vector.end(), 737);
    vector.insert(vector.end(), 0);
    std::vector<int>::iterator iv = vector.begin();
    std::vector<int>::iterator ive = vector.end();
    ++iv;
    --iv;
    while (iv != ive)
    {
        std::cout << *iv << std::endl;
        ++iv;
    }

    return 0;
}
