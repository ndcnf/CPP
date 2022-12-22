/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:23:17 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/22 17:50:59 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include	<iostream>
#include	"Zombie.hpp"

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

int		main(void)
{
	Zombie	Barbara;
	Barbara.setName("Barbara");
	Barbara.announce();

	Zombie	*George = newZombie("George A.");
	George->announce();
	delete George;

	randomChump("Shaun");

	return (0);
}
