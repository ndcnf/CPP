/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:02:24 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/24 10:47:38 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_HPP
# define CAST_HPP

# include <iostream>
# include <cmath>
# include <string>
# include <iomanip>

class cast
{
public:
	cast(std::string conv);
	cast(cast const & src);
	cast	&operator=(cast const & rhs);

	void	detection(std::string src);
	void	exception(std::string src);
	void	selection(std::string src);

	void	SrcChar(std::string src);
	void	SrcInt(std::string src);
	void	SrcFloat(std::string src);
	void	SrcDouble(std::string src);

	void	printChar();
	void	printInt();
	void	printFloat();
	void	printDouble();

	char	getChar() const;
	int		getInt() const;
	float	getFloat() const;
	double	getDouble() const;

	bool	getValid() const;

	~cast();

private:
	cast();

	std::string _param;

	char	_char;
	int		_int;
	float	_float;
	double	_double;

	bool	_isChar;
	bool	_isInt;
	bool	_isFloat;
	bool	_isDouble;

	bool	_hasPoint;
	bool	_hasSign;
	bool	_hasF;
	bool	_isNanInf;
	bool	_isValid;
};

#endif
