/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:14:18 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/26 14:46:51 by nchennaf         ###   ########.fr       */
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
	std::string		word;
	std::string		after;

	if (ifs.is_open())
	{
	// 	//NOTE lecture char par char. Exemple pris de cpluscplus.com, a modifier
	// 	char c = ifs.get();
		while (ifs.good())
		{
			ifs >> word;
			if (argv[2] == word)
				word = argv[3];
			std::cout	<< word << " ";
		}
	// 	while (ifs.good())
	// 	{
	// 		std::cout << c;
	// 		c = ifs.get();
	// 	}
	}
	else
	{
		std::cout	<< "Error opening file"
					<< std::endl;
	}
	//NOTE Fin de l'exemple

	// while (ifs.good())
	// {
	// 	ifs >> before;
	// 	std::cout	<< before << " ";
	// }
	//TODO faire une boucle, car cela ne prend qu'un seul mot a la fois
	//NOTE peut-etre https://cplusplus.com/reference/istream/istream/read/

	// std::cout	<< before
	// 			<< std::endl;

	ifs.close();

	// file = argv[1];
	// file += ".replace";
	// std::ofstrean	ofs(file);


	return (0);
}
