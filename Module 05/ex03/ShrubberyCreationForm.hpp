/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:32:16 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/17 13:41:03 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <fstream>
# include "AForm.hpp"

# define TOP "  /\\ \n"
# define MID " /  \\ \n"
# define LOW "/____\\ \n"
# define TRK "  ||\n"

# define LVL_SIGN_SHR 145
# define LVL_EXEC_SHR 137

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

		virtual void	execute(Bureaucrat const & executor) const;

	private:
		std::string	_target;
};

#endif
