// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

#include "MutantStack.hpp"

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	std::vector<std::string> vector_str;
// 	std::vector<int> vector_int;
// 	std::stack<int> stack_int;
// 	std::vector<Buffer> vector_buffer;
// 	std::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	// std::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	std::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}

// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(std::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;
// 	{
// 		std::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }


int main()
{
	{
		std::cout << "--- BASIC TEST REQUIRED ---" << std::endl;

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);

		std::cout << "* 2 elements added (push/push_back) *" << std::endl;
		std::cout << std::endl;

		std::cout << "[ 17]" << std::endl;
		std::cout << "[  5]" << std::endl;

		std::cout << "Top of the stack (top/back): ";
		std::cout << mstack.top() << std::endl;
		std::cout << std::endl;

		mstack.pop();
		std::cout << "* 1 element removed (pop/pop_back) *" << std::endl;
		std::cout << std::endl;

		std::cout << "[  5]" << std::endl;
		std::cout << "Size of the stack: ";
		std::cout << mstack.size() << std::endl;
		std::cout << std::endl;

		mstack.push(3);
		mstack.push(56);
		mstack.push(737);

		std::cout << "* 3 elements added (push/push_back) *" << std::endl;
		std::cout << std::endl;

		std::cout << "[737]" << std::endl;
		std::cout << "[ 56]" << std::endl;
		std::cout << "[  3]" << std::endl;
		std::cout << "[  5]" << std::endl;
		std::cout << "Top of the stack (top/back): ";
		std::cout << mstack.top() << std::endl;
		std::cout << std::endl;

		mstack.push(0);

		std::cout << "* 1 element added (push/push_back) *" << std::endl;
		std::cout << std::endl;

		std::cout << "[  0]" << std::endl;
		std::cout << "[737]" << std::endl;
		std::cout << "[ 56]" << std::endl;
		std::cout << "[  3]" << std::endl;
		std::cout << "[  5]" << std::endl;
		std::cout << std::endl;

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		std::cout << "Stack from bottom to top: " << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "- Some additionnal tests -" << std::endl;
		std::stack<int> s(mstack);
		std::cout << std::endl;
		std::cout << "Size of the duplicate stack S (5): " << s.size() << std::endl;

		MutantStack<int> p(mstack);
		p.push(7);
		std::cout << "Size of the stack P (6): " << p.size() << std::endl;
		MutantStack<int>::iterator itp = p.begin();
		MutantStack<int>::iterator itep = p.end();
		std::cout << "Stack P from bottom to top: " << std::endl;
		while (itp != itep)
		{
			std::cout << *itp << std::endl;
			++itp;
		}
	}

	std::cout << std::endl;

	{
		std::cout << "--- TESTS WITH LIST (LIGHTER VIEW)---" << std::endl;

		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << "* 2 elements added (push/push_back) *" << std::endl;
		std::cout << std::endl;

		std::cout << "Top of the stack (top/back): ";
		std::cout << mstack.back() << std::endl;
		std::cout << std::endl;

		mstack.pop_back();
		std::cout << "* 1 element removed (pop/pop_back) *" << std::endl;
		std::cout << std::endl;

		std::cout << "Size of the stack: ";
		std::cout << mstack.size() << std::endl;
		std::cout << std::endl;

		mstack.push_back(3);
		mstack.push_back(56);
		mstack.push_back(737);

		std::cout << "* 3 elements added (push/push_back) *" << std::endl;
		std::cout << std::endl;

		std::cout << "Top of the stack (top/back): ";
		std::cout << mstack.back() << std::endl;
		std::cout << std::endl;

		mstack.push_back(0);

		std::cout << "* 1 element added (push/push_back) *" << std::endl;
		std::cout << std::endl;

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;

		std::cout << "Stack from bottom to top: " << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	return 0;
}
