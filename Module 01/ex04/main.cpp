/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:14:18 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/28 10:33:22 by nchennaf         ###   ########.fr       */
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

	std::string		fileContent;
	std::string		file = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];

	fileContent = getFileContent(argv[1]);

	std::size_t		pos = fileContent.find(s1);
	bool			occurrenceFound = true;

	if (pos == std::string::npos)
	{
		std::cout	<< "Error: Nothing to replace. No file created."
					<< std::endl;
		occurrenceFound = false;
	}

	while (pos != std::string::npos)
	{
		fileContent.erase(pos, s1.length());
		fileContent.insert(pos, s2);
		pos = fileContent.find(s1, pos+1);
	}

	if (occurrenceFound)
	{
		file += ".replace";

		std::ofstream	ofs(file);
		ofs << fileContent;
		std::cout	<< "File: " << file << "created"
					<< std::endl;
		ofs.close();
	}

	return (0);
}
