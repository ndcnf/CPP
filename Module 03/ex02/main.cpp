/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:25:33 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/06 13:41:22 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap	guy("Guy");
	ClapTrap	jocelyne("Jocelyne");
	ClapTrap	someone;

	ScavTrap	something;
	ScavTrap	t800("T-800");

	FragTrap	dude;
	FragTrap	chad("Chad");

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
	t800.guardGate();
	something.guardGate();
	something.attack("T-800");
	t800.takeDamage(300);
	t800.attack("Guy");

	chad.highFivesGuys();
	if (!chad.getHighFiveAcknoledged())
	{
		dude.attack("Chad");
		chad.takeDamage(300);
	}

	return (0);
}
