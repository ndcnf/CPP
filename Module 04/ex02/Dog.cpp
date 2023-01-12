/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:28:06 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/12 13:32:54 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():
	AAnimal()
{
	_type = "dog";
	_brain = new Brain();
	std::cout	<< "the " << _type << " is waking up and gently wiggling its tail."
				<< std::endl;
}

Dog::~Dog()
{
	std::cout	<< "the " << _type << " drops its favorite ball and is ready to bed."
				<< std::endl;
	delete _brain;
}

Dog::Dog(Dog const & src)
{
	*this = src;
	std::cout	<< "a dog has been cloned"
				<< std::endl;
}

Dog		&Dog::operator=(Dog const & rhs)
{
	if (this != &rhs)
		this->AAnimal::operator=(rhs);
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout	<< "The " << _type << " says \"woof\""
				<< std::endl;
}

void	Dog::ideaSeeker(int i) const
{
	std::cout << this->_brain->getIdeas(i) << std::endl;
}
