/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:14:18 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/27 16:46:23 by nchennaf         ###   ########.fr       */
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
	//TODO verifier si le fichier est lisible (droits de lecture)

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

	//////////////////////////////////////////////////
	//SECTION - File name OK
	std::string	file;

	file = argv[1];
	file += ".replace";
	std::cout << file << std::endl;
	//////////////////////////////////////////////////

	// std::ofstrean	ofs(file);
	// ofs << fileContent << std::endl;
	// ofs.close();

	return (0);
}
