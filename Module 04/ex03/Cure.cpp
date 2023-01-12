/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:28:25 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/12 10:09:58 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{}
Cure::Cure(Cure const & src)
{
	*this = src;
}
~Cure::Cure()
{}

Cure	&Cure::operator=(Cure const & rhs)
{
	if (this != &rhs)
		//variables to copy
}

// AMateria*	Cure::clone() const
// {

// }
// void		Cure::use(ICharacter& target)
// {

// }
