// VectMap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <map>


int main()
{

	//auto start = std::chrono::system_clock::now();
	//auto end = std::chrono::system_clock::now();
    int size = 10000;
	int step = 50;
    int* matrix = new int[size];
	for (int i = 0; i < size; ++i)
	{
		matrix[i] = 0;
	}

    
	//std::map<int> m_matrix;

	std::cout << "Matrix size: " << size << std::endl;


	for (int numOfOnes = step; numOfOnes <= size; numOfOnes += step)
	{
		int onesToAdd = step;
		int possition;
		do
		{
			possition = rand() % size;
			if (matrix[possition] == 0)
			{
				matrix[possition] = 1;
				--onesToAdd;
			}
		} while (onesToAdd > 0);
		

		std::vector<int> v_matrix;
		auto v_start = std::chrono::system_clock::now();
		for (int i = 0; i < size; i++)
		{
			v_matrix.push_back(matrix[i]);
		}
		auto v_end = std::chrono::system_clock::now();
		std::chrono::duration<int64_t, std::nano> v_time = v_end - v_start;


		std::map<int,int> m_matrix;
		auto m_start = std::chrono::system_clock::now();
		for (int i = 0; i < size; i++)
		{
			if(matrix[i] == 1)
				m_matrix[i] = 1;
		}
		auto m_end = std::chrono::system_clock::now();
		std::chrono::duration<int64_t, std::nano> m_time = m_end - m_start;

		std::cout << "Matrix has " << 100.0f * numOfOnes / size << "% of 1" << std::endl;
		std::cout << "Time to write vector:\t" << v_time.count() << std::endl;
		std::cout << "Time to write map:\t" << m_time.count() << std::endl;
		std::cout << ((m_time.count() < v_time.count()) ? "Map faster" : "Vector faster") << std::endl << std::endl;
	}

    delete[] matrix;
    matrix = nullptr;
}