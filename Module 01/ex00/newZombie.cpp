/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:04:53 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/22 17:15:21 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

//TODO - Verifier que cette fonction doit etre ici et pas ailleurs
//NOTE - Cette fonction doit rester telle quelle
Zombie*	newZombie(std::string name)
{
	Zombie* newOne = new Zombie(name);
	this->setName(name);
	return (newOne);
}
