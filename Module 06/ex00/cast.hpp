/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:02:24 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/23 14:10:10 by nchennaf         ###   ########.fr       */
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
	void	exceptions(std::string src);
	char	toChar(std::string src);
	int		toInt(std::string src);
	float	toFloat(std::string src);
	double	toDouble(std::string src);

	char	getChar(std::string src) const;
	int		getInt(std::string src) const;
	float	getFloat(std::string src) const;
	double	getDouble(std::string src) const;

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
