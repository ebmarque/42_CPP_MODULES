/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:59:07 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/17 20:37:22 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"


int main()
{
    int N = 6;
    AAnimal *animals[N];

    std::cout << std::endl << "---- Creating animals -----" << std::endl << std::endl;
    for(int i = 0; i < N; i++)
    {
        std::cout << "[ " << i << " ]" << std::endl;
        if(i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << std::endl << "---- Deleting animals -----" << std::endl << std::endl;
    for(int i = 0; i < N; i++)
    {
        std::cout << "[ " << i << " ]" << std::endl;
        delete animals[i];
    }
}