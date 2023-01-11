/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:25:00 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/11 16:42:48 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{}

AMateria::AMateria(std::string const & type): _type(type)
{}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
}

AMateria::~AMateria()
{}

AMateria	&AMateria::operator=(AMateria const & rhs)
{
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void		AMateria::use(ICharacter& target)
{
	(void)target;
}
