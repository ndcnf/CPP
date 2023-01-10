/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:06:43 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/10 13:03:07 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int		main()
{
	{
		std::cout	<< "--- No leaky animals allowed ---" << std::endl;
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}

	std::cout << std::endl;

	{
		int		nbAnimals;

		nbAnimals = 6;
		std::cout	<< "--- " << nbAnimals << " cats and dogs in a cute little box ---" << std::endl;
		AAnimal* animal[nbAnimals];

		for (int i = 0; i < nbAnimals; i++)
		{
			if (i % 2)
				animal[i] = new Cat();
			else
				animal[i] = new Dog();
		}

		for (int j = 0; j < nbAnimals; j++)
			delete animal[j];
	}

	std::cout << std::endl;

	{
		std::cout	<< "--- A cat and a dog thinking about important stuff ---" << std::endl;
		Dog j = Dog();
		Cat i = Cat();

		std::cout << "the cat thinks: ";
		j.ideaSeeker(0);
		std::cout << "the dog thinks: ";
		i.ideaSeeker(0);
	}

	return 0;
}
