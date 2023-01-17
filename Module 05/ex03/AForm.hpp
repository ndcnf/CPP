/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:45:11 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/17 14:57:46 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class AForm;

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm();
		AForm(AForm const & src);
		AForm(std::string name, int signGrade, int execGrade);
		virtual ~AForm();
		AForm	&operator=(AForm const & rhs);

		//////////////////////////////////////////////

		void			beSigned(Bureaucrat &b);
		virtual void	execute(Bureaucrat const & executor) const = 0;

		//////////////////////////////////////////////

		std::string		getName() const;
		int				getFormSigned() const;
		int				getSignGrade() const;
		int				getExecGrade() const;

		//////////////////////////////////////////////

		class NotSigned:
			public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;
};

std::ostream	&operator<<(std::ostream & o, AForm const & rhs);

#endif
