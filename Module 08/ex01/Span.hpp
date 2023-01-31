/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:24:39 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/31 13:48:06 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <stdexcept>
# include <vector>

class Span
{
	public:
		Span();
		Span(unsigned int n);
		Span(Span const &src);
		Span &operator=(Span const &rhs);
		~Span();

		void			addNumber(int i);
		unsigned int	longestSpan();
		unsigned int	shortestSpan();
		void			generateTab();

		class invalidSize: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: the size is not valid.");
				}
		};

		class invalidData: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: the data is not valid.");
				}
		};

	private:
		unsigned int				_n;
		std::vector<unsigned int>	_data;
};

#endif
