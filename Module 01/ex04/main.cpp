/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:14:18 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/27 13:47:51 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "substitute.hpp"


// std::string	getFileContent(std::string file)
// {

// }

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
	//TODO Remplacer les OCCURENCES, pas les mots entiers. Voir https://cplusplus.com/reference/string/string/?kw=string (erase, substr, ...)

	std::ifstream	ifs(argv[1]);
	std::string		word;
	std::string		content;
	// std::size_t		pos;

	if (ifs.is_open())
	{
		char c = ifs.get();
		while (ifs.good())
		{
			// ifs >> word;

			// std::cout << c;
			content += c;
			c = ifs.get();

			if (argv[2] == word)
				word = argv[3];
			else
			{
				int	j = 0;
				for (int i = 0; i < word.length(); i++)
				{
					if (word[i] == argv[2][j])
						// std::cout << word[i] << "-";
					j++;
				}

			}

			// if (!ifs.eof())
			// 	content += " ";
			// 	// std::cout	<< word << " ";
			// content += word;
			// pos = word.find(argv[2]);
			// std::cout << pos << std::endl;
		}
		std::cout << content;
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

	//NOTE peut-etre https://cplusplus.com/reference/istream/istream/read/

	// std::cout	<< before
	// 			<< std::endl;

	ifs.close();

	//////////////////////////////////////////////////
	// //SECTION - File name OK
	// std::string	file;

	// file = argv[1];
	// file += ".replace";
	// std::cout << file << std::endl;
	//////////////////////////////////////////////////

	// std::ofstrean	ofs(file);


	return (0);
}
