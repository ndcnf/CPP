/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:14:18 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/23 18:22:15 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "substitute.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout	<< "wrong number of arguments"
					<< std::endl;
		return (1);
	}
	//TODO verifications avant
	//TODO verifier que le fichier existe
	//TODO verifier si le fichier est lisible (droits de lecture)


	std::ifstream	ifs(argv[1]);
	std::string		before;
	std::string		after;

	ifs >> before; //TODO faire une boucle, car cela ne prend qu'un seul mot a la fois

	std::cout	<< before
				<< std::endl;

	ifs.close();

	// file = argv[1];
	// file += ".replace";
	// std::ofstrean	ofs(file);


	return (0);
}
