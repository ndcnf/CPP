/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:02:24 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/23 13:04:55 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_HPP
# define CAST_HPP

# include <iostream>
# include <cmath>

class cast
{
public:
	cast(std::string conv);
	cast(cast const & src);
	cast	&operator=(cast const & rhs);

	void	detection(std::string src);
	char	toChar(std::string src);
	int		toInt(std::string src);
	float	toFloat(std::string src);
	double	toDouble(std::string src);

	~cast();

private:
	cast();

	char	_char;
	int		_int;
	float	_float;
	double	_double;
	bool	_hasPoint;
	bool	_hasSign;
	bool	_hasF;
};





#endif
