/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:01:44 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/16 10:12:04 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	"Class.Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Contact::~Contact(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}
