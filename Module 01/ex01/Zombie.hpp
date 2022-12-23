/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:31:56 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/23 12:04:11 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include	<iostream>
# include	<string>

# define INFECTED_N 3
# define SLOW_N 11

class Zombie
{
	public:
		Zombie();
		~Zombie();

		void		announce();
		std::string	getName() const;
		void		setName(std::string name);
	private:
		std::string	_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
