/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:00:16 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/16 15:28:26 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		int	i = 1;
		while (i < argc)
		{
			std::string	str(argv[i]);
			for (int j = 0; j < (int)str.length(); j++)
				std::cout << (char)toupper(str[j]);
			i++;
		}
		std::cout << std::endl;
	}
	return 0;
}
