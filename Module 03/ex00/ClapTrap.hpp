/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:59:42 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/04 11:40:08 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define HP 10
# define EP 10
# define AD 0

class ClapTrap
{
	public:
		ClapTrap(std::string s);
		ClapTrap(ClapTrap const & src);
		~ClapTrap();

		ClapTrap &operator=(ClapTrap const & rhs);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:
		std::string		_name;
		int	_hitPoints;
		int	_energyPoints;
		int	_attackDamage;
};

#endif
