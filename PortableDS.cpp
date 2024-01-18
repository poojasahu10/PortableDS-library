#include<iostream>
using namespace std;
#include <chrono>
#include "plf_colony.h"
#include <list>
#include <vector>

#define INTDATACOUNT 200000
class PaceTimer
{
	chrono::time_point<chrono::high_resolution_clock> m_StartTime;
public:
	PaceTimer()
	{
		m_StartTime = chrono::high_resolution_clock::now();
	}
	~PaceTimer()
	{
		Stop();
	}
	void Stop()
	{
		auto endTime = chrono::high_resolution_clock::now();
		auto start = chrono::time_point_cast<chrono::microseconds>(m_StartTime).time_since_epoch().count();
		auto end = chrono::time_point_cast<chrono::microseconds>(endTime).time_since_epoch().count();
		double duration = (end - start) * 0.001;
		cout << duration << " ms\n";
	}
};

int main()
{
	int array[200000];
	srand(time(NULL));
	for (int i = 0; i != INTDATACOUNT; ++i)
	{
		int random = rand() % 100;
		array[i] = random;
	}
	plf::colony<int> i_colony;
	cout << "Insertion PLF : ";
	{
		// Insert 100 ints:
		PaceTimer obj;
		for (int i = 0; i != INTDATACOUNT; ++i)
		{
			i_colony.insert(array[i]);
		}
	}
	list<int> listTest;
	cout << "Insertion std::list : ";
	{
		// Insert 100 ints:
		PaceTimer obj;
		for (int i = 0; i != INTDATACOUNT; ++i)
		{
			listTest.emplace_back(array[i]);
		}
	}
	vector<int> vectorTest;
	cout << "Insertion std::vector : ";
	{
		// Insert 100 ints:
		PaceTimer obj;
		for (int i = 0; i != INTDATACOUNT; ++i)
		{
			vectorTest.emplace_back(array[i]);
		}
	}
	cout << endl << "------------------" << endl;
	// Erase half of them:
	cout << "Deletion PLF : ";
	{
		PaceTimer obj;
		for (plf::colony<int>::iterator it = i_colony.begin(); it != i_colony.end(); ++it)
		{
			it = i_colony.erase(it);
		}
	}
	cout << "Deletion std::list : ";
	{
		// Insert 100 ints:
		PaceTimer obj;
		for (list<int>::iterator it = listTest.begin(); it != listTest.end(); ++it)
		{
			it = listTest.erase(it);
		}
	}
	cout << "Deletion std::vector : ";
	{
		// Insert 100 ints:
		PaceTimer obj;
		for (vector<int>::iterator it = vectorTest.begin(); it != vectorTest.end(); ++it)
		{
			it = vectorTest.erase(it);
		}
	}

	cout << endl << "------------------" << endl;
	cout << "Iteration PLF : ";
	{
		// Insert 100 ints:
		PaceTimer obj;
		// Total the remaining ints:
		int total = 0;

		for (plf::colony<int>::iterator it = i_colony.begin(); it != i_colony.end(); ++it)
		{
			total += 1;
		}
	}
	cout << "Iteration std::list : ";
	{
		// Insert 100 ints:
		PaceTimer obj;
		int total = 0;
		for (list<int>::iterator it= listTest.begin(); it != listTest.end(); ++it)
		{
			total += 1;
		}
	}
	cout << "Iteration std::vector : ";
	{
		// Insert 100 ints:
		PaceTimer obj;
		// Total the remaining ints:
		int total = 0;

		for (vector<int>::iterator it= vectorTest.begin(); it != vectorTest.end(); ++it)
		{
			total += 1;
		}
	}

	cout << endl << "------------------" << endl;
	cout << "Sort::plf : ";
	{
		// Insert 100 ints:
		PaceTimer obj;
		i_colony.sort();
	}
	cout << "Sort::list : ";
	{
		// Insert 100 ints:
		PaceTimer obj;
		listTest.sort();
	}
	cout << "Sort::vector : ";
	{
		// Insert 100 ints:
		PaceTimer obj;
		sort(vectorTest.begin(), vectorTest.end());
	}

	cout << endl << "------------------" << endl;
	cout << "Find::plf : ";
	{
		// Insert 100 ints:
		PaceTimer obj;
		find(i_colony.begin(), i_colony.end(), 14);
	}
	cout << "Find::list : " ;
	{
		// Insert 100 ints:
		PaceTimer obj;
		find(listTest.begin(), listTest.end(), 14);
	}
	cout << "Find::vector : " ;
	{
		// Insert 100 ints:
		PaceTimer obj;
		find(vectorTest.begin(), vectorTest.end(), 14);
	}
	//std::cout << "Total: " << total << std::endl;
	//std::cin.get();
	return 0;
}