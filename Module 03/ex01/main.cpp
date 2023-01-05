/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:25:33 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/05 15:56:59 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	guy("Guy");
	ClapTrap	jocelyne("Jocelyne");
	ClapTrap	someone;
	ScavTrap	something;
	ScavTrap	t800("T-800");

	guy.attack("Jocelyne");
	jocelyne.takeDamage(13);

	guy.beRepaired(50);

	guy.attack("Julien");
	someone.takeDamage(11);

	guy.beRepaired(4);

	guy.attack("Jocelyne");
	jocelyne.takeDamage(3);
	jocelyne.beRepaired(4);

	someone.attack("Guy");
	guy.takeDamage(1);

	something.attack("Guy");
	guy.takeDamage(2);

	t800.attack("Guy");
	guy.takeDamage(3);

	t800.beRepaired(100);
	something.beRepaired(25);

	t800.guardGate();
	something.guardGate();

	return (0);
}
