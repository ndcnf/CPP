/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:38:48 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/16 10:12:48 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	"Class.Phonebook.hpp"

Phonebook::Phonebook(void)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}
