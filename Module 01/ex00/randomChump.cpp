/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:52:23 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/22 17:51:13 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

//TODO - Verifier que cette fonction doit etre ici et pas ailleurs
//NOTE - Cette fonction doit rester telle quelle
void	randomChump(std::string name)
{
	Zombie	*Shaun = new Zombie();
	Shaun->setName(name);
	Shaun->announce();
	delete Shaun;
}
