/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:19:43 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/06 16:25:44 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():
	Animal()
{
	_type = "cat";
	std::cout	<< "the " << _type << "is waking up."
				<< std::endl;
}

Cat::~Cat()
{
	std::cout	<< "the " << _type << "is sleeping."
				<< std::endl;
}
