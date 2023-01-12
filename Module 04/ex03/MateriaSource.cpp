/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:48:14 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/12 10:07:04 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	*this = src;
}

MateriaSource::~MateriaSource()
{}

MateriaSource	& MateriaSource::operator=(MateriaSource const & rhs)
{
	if (this != &rhs)
	{
		//variables to copy
	}
}

// void		MateriaSource::learnMateria(AMateria*)
// {

// }

// AMateria*	MateriaSource::createMateria(std::string const & type)
// {

// }


