/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:06:43 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/09 13:51:15 by nchennaf         ###   ########.fr       */
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
		std::cout	<< "--- All your right animals ---" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	std::cout << std::endl;

	{
		std::cout	<< "--- All your wrong animals ---" << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();

		std::cout << meta->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the wrong cat sound!
		meta->makeSound();

		delete meta;
		delete i;
	}

	std::cout << std::endl;

	{
		std::cout	<< "--- All kind of animals ---" << std::endl;
		const Cat* cat = new Cat();
		const Dog* dog = new Dog();
		const WrongCat* wCat = new WrongCat();

		std::cout << cat->getType() << " " << std::endl;
		std::cout << dog->getType() << " " << std::endl;
		std::cout << wCat->getType() << " " << std::endl;
		cat->makeSound(); //will output the cat sound!
		dog->makeSound();
		wCat->makeSound();

		delete cat;
		delete dog;
		delete wCat;
	}

	return 0;
}
