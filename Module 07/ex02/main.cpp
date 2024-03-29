#include <iostream>
#include "Array.hpp"

#define MAX_VAL 10
int main(int, char**)
{
	{
		Array<int> numbers;
		try
		{
			std::cout << "-- trying an empty array with no parameter : should be out of range --" << std::endl;
			numbers[0] = 1;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		int		arraySize = 6;
		Array<int> numbers(6);
		try
		{
			std::cout << "-- trying array, of " << arraySize << " values --" << std::endl;
			srand(time(NULL));
			std::cout << "-- values of array, for control --" << std::endl;
			for (int i = 0; i < 6; i++)
			{
				const int value = rand();
				numbers[i] = value;
				std::cout << numbers[i] << std::endl;
			}
			std::cout << "-- size of this array, via size() --" << std::endl;
			std::cout << numbers.size() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!" << std::endl;
				return 1;
			}
		}
		try
		{
			std::cout << "-- trying negative index : should be out of range --" << std::endl;
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "-- trying an empty array : should be out of range --" << std::endl;
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "-- values of array should be ok --" << std::endl;
		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
			std::cout << numbers[i] << std::endl;
		}
		delete [] mirror;
	}

	return 0;
}
