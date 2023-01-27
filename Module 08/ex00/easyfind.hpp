/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:36:20 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/27 13:59:53 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <stdexcept>

class NotFound: public std::exception
{
	public:
	virtual const char* what() const throw()
	{
		return ("No occurence found.");
	}
};

template <typename T>
void	easyfind(T &first, int second)
{
	typename T::iterator	it;
	it = std::find(first.begin(), first.end(), second);

	if(it == first.end())
		throw(NotFound());
	std::cout << "Found: " << *it << std::endl;
}

#endif
