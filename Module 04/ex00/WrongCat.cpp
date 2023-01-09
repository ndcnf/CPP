/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:19:43 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/09 13:53:18 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat():
	WrongAnimal()
{
	_type = "Not your expected cat";
	std::cout	<< _type << " is waking up."
				<< std::endl;
}

WrongCat::~WrongCat()
{
	std::cout	<< "the " << _type << " is ready to bed."
				<< std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const & rhs)
{
	if (this != &rhs)
		this->WrongAnimal::operator=(rhs);
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout	<< "mew mew"
				<< std::endl;
}
