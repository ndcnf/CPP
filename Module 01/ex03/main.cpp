/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:09:14 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/26 10:35:27 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{
	{
		Weapon	sword = Weapon("Devil Sparda sword");

		HumanA	bob("Bob", sword);
		bob.attack();
		sword.setType("Ebony & Ivory guns");
		bob.attack();
	}

	{
		Weapon	guns = Weapon("Devil Sparda sword");

		HumanB	alice("Alice");
		alice.setWeapon(guns);
		alice.attack();
		guns.setType("Ebony & Ivory guns");
		alice.attack();
	}
	return (0);
}
