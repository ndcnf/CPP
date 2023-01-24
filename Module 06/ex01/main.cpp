/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:56:51 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/24 15:25:34 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.hpp"
#include "Data.hpp"

int	main()
{
	Data		source;

	source.anInt = 10;
	source.aChar = 'a';
	source.aFloat = 42.5f;

	std::cout	<< "[PRELIMINARY TESTS]" << std::endl;
	std::cout	<< "Address (source)  : " << &source << std::endl;
	std::cout	<< "Int value         : " << source.anInt << std::endl;
	std::cout	<< "Char value        : " << source.aChar << std::endl;
	std::cout	<< "Float value       : " << source.aFloat << std::endl;
	std::cout	<< std::endl;

	uintptr_t	ptr = serialize(&source);

	std::cout	<< "[SERIAL]" << std::endl;
	std::cout	<< "Address (serial)  : " << &ptr << std::endl;
	int* f = reinterpret_cast<int *>(ptr);
	std::cout	<< "Int value         : " << *f << std::endl;
	f++;
	std::cout	<< "Char value        : " << *(reinterpret_cast<char *>(f)) << std::endl;
	f++;
	std::cout	<< "Float value       : " << *(reinterpret_cast<float *>(f)) << std::endl;
	std::cout	<< std::endl;

	Data		*newOne = deserialize(ptr);

	std::cout	<< "[DESERIAL]" << std::endl;
	std::cout	<< "Address (deserial): " << newOne << std::endl;
	std::cout	<< "Int value         : " << newOne->anInt << std::endl;
	std::cout	<< "Char value        : " << newOne->aChar << std::endl;
	std::cout	<< "Float value       : " << newOne->aFloat << std::endl;

	return (0);
}




// int main()
// {
// 	Data original;
// 	Data *unserial;
// 	int *head;
// 	uintptr_t serial;

// 	// original.anInt = 42;
// 	// original.aChar = '*';

// 	// std::cout << "Data Original address " << &original << std::endl;
// 	// std::cout << "Data Original int value: " << original.anInt << std::endl;
// 	// std::cout << "Data Original char value: " << original.aChar << std::endl;
// 	// std::cout << std::endl;

// 	std::cout << "serialize" << std::endl;
// 	serial = serialize(&original);
// 	std::cout << "uintptr_t address: " << &serial << std::endl;

// 	head = reinterpret_cast<int *>(serial);
// 	std::cout << "head int: " << *head << std::endl;
// 	head++;
// 	std::cout << "head char: " << *reinterpret_cast<char *>(head) << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "unserialize" << std::endl;
// 	unserial = deserialize(serial);
// 	std::cout << "Data unserial address " << unserial << std::endl;
// 	std::cout << "Data unserial int value: " << unserial->anInt << std::endl;
// 	std::cout << "Data unserial char value: " << unserial->aChar << std::endl;
// }
