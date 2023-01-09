/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:06:43 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/09 17:18:52 by nchennaf         ###   ########.fr       */
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

		const Animal* animal[6];

		for (int i = 0; i < 6; i++)
		{
			if (i % 2)
				animal[i] = new Cat();
			else
				animal[i] = new Dog();
			std::cout << i << std::endl;
		}

		for (int j = 0; j < 6; j++)
		{
			std::cout << j << std::endl;
			delete animal[j];
		}


		// const Animal* dogA = new Dog();
		// const Animal* catA = new Cat();

		// std::cout << dogA->getType() << " " << std::endl;
		// std::cout << catA->getType() << " " << std::endl;
		// dogA->makeSound();
		// catA->makeSound();

		// delete animal;
		// delete catA;
	}

	// std::cout << std::endl;

	// {
	// 	std::cout	<< "--- The wrong ones don't think ---" << std::endl;
	// 	const WrongAnimal* meta = new WrongAnimal();
	// 	const WrongAnimal* i = new WrongCat();

	// 	std::cout << "I'm " << meta->getType() << " " << std::endl;
	// 	std::cout << "I'm an " << i->getType() << " " << std::endl;
	// 	i->makeSound(); //will output the wrong cat sound!
	// 	meta->makeSound();

	// 	delete meta;
	// 	delete i;
	// }

	// std::cout << std::endl;

	// {
	// 	std::cout	<< "--- All kind of thinking animals ---" << std::endl;
	// 	const Cat* cat = new Cat();
	// 	const Dog* dog = new Dog();
	// 	const WrongCat* wCat = new WrongCat();

	// 	std::cout << "I'm a " << cat->getType() << " " << std::endl;
	// 	std::cout << "I'm a " << dog->getType() << " " << std::endl;
	// 	std::cout << "I'm a " << wCat->getType() << " " << std::endl;
	// 	cat->makeSound(); //will output the cat sound!
	// 	dog->makeSound();
	// 	wCat->makeSound();

	// 	delete cat;
	// 	delete dog;
	// 	delete wCat;
	// }

	return 0;
}
