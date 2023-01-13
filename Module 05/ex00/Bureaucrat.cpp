/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:15:25 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/13 10:25:01 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():
	_name("a random Vogon"),
	_grade(150)
{
	std::cout	<< _name << " [" << _grade << "]"
				<< " glares into the void of their life."
				<< std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):
	_name(name),
	_grade(grade)
{
	std::cout	<< _name << " [" << _grade << "]"
				<< " glares into the void of their life."
				<< std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
	std::cout	<< _name << " [" << _grade << "]"
				<< " sighs and vanishes in their cubicule."
				<< std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_grade = rhs._grade;
	}
	return (*this);
}

