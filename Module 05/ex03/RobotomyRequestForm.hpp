/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:41:14 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/17 14:04:13 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <fstream>
# include "AForm.hpp"

# define LVL_SIGN_ROB 72
# define LVL_EXEC_ROB 45

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

		virtual void	execute(Bureaucrat const & executor) const;

		std::string		getTarget() const;

		class RobotomyFailed:
			public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string	_target;
};

#endif
