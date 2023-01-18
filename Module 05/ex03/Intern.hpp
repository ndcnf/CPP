/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:54:55 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/18 16:06:01 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Intern;

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <stdexcept>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# define N_FORMS 3

class Intern
{
	public:
		Intern();
		Intern(Intern const & src);
		Intern &operator=(Intern const & rhs);
		~Intern();

		AForm*	makeForm(std::string formName, std::string targetForm);

		class NoForm:
			public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		AForm* shrubberyForm(std::string target);
		AForm* robotomyForm(std::string target);
		AForm* pardonForm(std::string target);

	// private:
	// 	std::string	_forms[N_FORMS];

	// 	void	(*_function[N_FORMS])();
};

#endif
