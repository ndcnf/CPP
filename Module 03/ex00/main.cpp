/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:25:33 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/03 18:16:09 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	guy("Guy");
	ClapTrap	jocelyne("Jocelyne");

	guy.attack("Jocelyne");
	jocelyne.takeDamage(3); //TODO Jocelyne ne devrait pas prendre de degat si impossible d'attaquer
	guy.attack("Jocelyne");
	jocelyne.takeDamage(3);

	return (0);
}
