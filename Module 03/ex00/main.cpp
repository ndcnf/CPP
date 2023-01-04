/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:25:33 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/04 15:12:27 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	guy("Guy");
	ClapTrap	jocelyne("Jocelyne");
	ClapTrap	someone;

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

	return (0);
}
