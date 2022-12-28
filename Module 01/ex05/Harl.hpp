/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:39:09 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/28 12:29:51 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

# define DEBUG		"I LOVE having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !"
# define INFO		"I cannot BELIEVE adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !"
# define WARNING	"I think I DESERVE to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
# define ERROR		"This is UNACCEPTABLE ! I want to speak to the manager NOW."

# define LVL_NB		4

class Harl
{
	public:
		Harl();
		~Harl();

		void	complain(std::string level);

	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

		void	(Harl::*_function[LVL_NB])();

		std::string	_level[LVL_NB];
};

#endif
