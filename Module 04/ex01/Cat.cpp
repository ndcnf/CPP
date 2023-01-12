/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:19:43 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/12 12:11:25 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():
	Animal()
{
	_type = "cat";
	_brain = new Brain();
	std::cout	<< "the " << _type << " is waking up and purring."
				<< std::endl;
}

Cat::~Cat()
{
	std::cout	<< "the " << _type << " is yawning and ready to bed."
				<< std::endl;
	delete _brain;
}

Cat::Cat(Cat const & src)
{
	*this = src;
	std::cout	<< "a cat has been cloned"
				<< std::endl;
}

Cat		&Cat::operator=(Cat const & rhs)
{
	if (this != &rhs)
		this->Animal::operator=(rhs);
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout	<< "The " << _type << " says \"maow\""
				<< std::endl;
}

void	Cat::ideaSeeker(int i) const
{
	std::cout << this->_brain->getIdeas(i) << std::endl;
}
