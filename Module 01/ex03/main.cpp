/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:09:14 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/23 16:49:35 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{
	{
		Weapon	club = Weapon("crude spiked club");

		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	{
		Weapon	club = Weapon("crude spiked club");

		HumanB	alice("Alice");
		alice.setWeapon(club);
		alice.attack();
		club.setType("some other type of club");
		alice.attack();
	}
	return (0);
}
