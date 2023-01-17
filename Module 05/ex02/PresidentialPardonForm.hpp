/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:23:17 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/17 17:24:59 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <fstream>
# include "AForm.hpp"

# define LVL_SIGN_PRE 25
# define LVL_EXEC_PRE 5

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

		virtual void	execute(Bureaucrat const & executor) const;

		std::string		getTarget() const;

	private:
		std::string	_target;
};

#endif
