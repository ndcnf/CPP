/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:14:18 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/27 15:59:35 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std::string	getFileContent(std::string file)
{
	std::ifstream	ifs(file);
	std::string		content;

	if (ifs.is_open())
	{
		char c = ifs.get();
		while (ifs.good())
		{
			content += c;
			c = ifs.get();
		}
	}
	else
	{
		std::cout	<< "Error: Opening file impossible"
					<< std::endl;
	}
	ifs.close();
	return (content);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout	<< "Error: Wrong number of arguments"
					<< std::endl;
		return (1);
	}
	//TODO verifications avant
	//TODO verifier que le fichier existe
	//TODO verifier si le fichier est lisible (droits de lecture)
	//TODO Remplacer les OCCURENCES, pas les mots entiers. Voir https://cplusplus.com/reference/string/string/?kw=string (erase, substr, ...)

	std::string		fileContent;

	fileContent = getFileContent(argv[1]);
	std::cout << fileContent; //NOTE Uniquement pour tester

	std::string		before = argv[2];
	std::string		after = argv[3];
	std::size_t		pos = fileContent.find(before);

	std::cout << "length: " << fileContent.length() << std::endl;
	std::cout << "pos-find: " << pos << std::endl;

	while (pos!= std::string::npos)
	{
		fileContent.erase(pos, before.length());
		fileContent.insert(pos, after);
		pos = fileContent.find(before, pos+1);
	}

	std::cout << "APRES: " << fileContent; //NOTE Uniquement pour tester

			// if (argv[2] == word)
			// 	word = argv[3];
			// else
			// {
			// 	int	j = 0;
			// 	for (int i = 0; i < word.length(); i++)
			// 	{
			// 		if (word[i] == argv[2][j])
			// 			// std::cout << word[i] << "-";
			// 		j++;
			// 	}

			// }

			// if (!ifs.eof())
			// 	content += " ";
			// 	// std::cout	<< word << " ";
			// content += word;
			// pos = word.find(argv[2]);
			// std::cout << pos << std::endl;
		// }




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
