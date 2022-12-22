/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:24:14 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/22 17:50:42 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_HPP
# define ZOMBIE_HPP
# include	<string>
# include	<iostream>

class Zombie
{
	public:
	Zombie();
	~Zombie();

	void	announce();
	void	setName(std::string name);

	private:
	std::string	_name;
};

#endif
