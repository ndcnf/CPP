/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:25:33 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/04 12:37:48 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	guy("Guy");
	ClapTrap	jocelyne("Jocelyne");

	guy.attack("Jocelyne");
	jocelyne.takeDamage(0); //TODO Jocelyne ne devrait pas prendre de degat si impossible d'attaquer
	// guy.beRepaired(50);
	guy.attack("Jocelyne");
	jocelyne.takeDamage(3);

	return (0);
}
