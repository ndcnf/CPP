/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:47:42 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/23 11:59:37 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

int	main()
{
	Zombie	*infected = zombieHorde(INFECTED_N, "an infected one");
	for (int i = 0; i < INFECTED_N; i++)
		infected->announce();
	delete [] infected;

	Zombie	*slow = zombieHorde(SLOW_N, "a slow one");
	for (int j = 0; j < SLOW_N; j++)
		slow->announce();
	delete [] slow;
	return (0);
}
