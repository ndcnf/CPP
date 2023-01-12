/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:06:43 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/12 11:47:24 by nchennaf         ###   ########.fr       */
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

		std::cout << "dog: ";
		std::cout << j->getType() << " " << std::endl;

		std::cout << "cat: ";
		std::cout << i->getType() << " " << std::endl;

		std::cout << i->getType() << ": ";
		i->makeSound(); //will output the cat sound!

		std::cout << j->getType() << ": ";
		j->makeSound(); //will output the dog sound!

		std::cout << meta->getType() << ": ";
		meta->makeSound(); //will output an animal sound!

		delete meta;
		delete j;
		delete i;
	}

	std::cout << std::endl;

	{
		std::cout	<< "--- All your wrong animals ---" << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();

		std::cout << "wrong animal: ";
		std::cout << meta->getType() << " " << std::endl;

		std::cout << "wrong cat: ";
		std::cout << i->getType() << " " << std::endl;

		std::cout << "the cat shouldn\'nt meow: ";
		i->makeSound();

		std::cout << "wrong animal, should say the same: ";
		meta->makeSound();

		delete meta;
		delete i;
	}

	std::cout << std::endl;

	{
		std::cout	<< "--- All animals are clearly defined ---" << std::endl;
		const Cat* cat = new Cat();
		const Dog* dog = new Dog();
		const WrongCat* wCat = new WrongCat();

		std::cout << cat->getType() << " " << std::endl;
		std::cout << dog->getType() << " " << std::endl;
		std::cout << wCat->getType() << " " << std::endl;
		cat->makeSound();
		dog->makeSound();
		wCat->makeSound();

		delete cat;
		delete dog;
		delete wCat;
	}

	return 0;
}
