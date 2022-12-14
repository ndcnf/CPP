/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:52:23 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/23 11:04:31 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	*Shaun = new Zombie();
	Shaun->setName(name);
	Shaun->announce();
	delete Shaun;
}
