/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:24:14 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/22 10:55:39 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

Zombie::Zombie()
{
	std::cout	<< "a zombie has risen" << std::endl;
	return;
}

Zombie::~Zombie()
{
	std::cout	<< "a zombie has fallen" << std::endl; //TODO - Changer pour afficher le nom du zombie
	return;
}
