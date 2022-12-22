/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:52:23 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/22 15:56:21 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

//TODO - Verifier que cette fonction doit etre ici et pas ailleurs
//NOTE - Cette fonction doit rester telle quelle
void	Zombie::randomChump(std::string name)
{
	Zombie::setName(name);
	std::cout	<< name
				<< ": BraiiiiiiinnnzzzZ..."
				<< std::endl;
}
