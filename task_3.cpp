#include "stdafx.h"
#include <iostream>

void read_2d_arr(int*** arr, int m, int n)
{
	for (int i = 0; i < m; i++) {
		std::cout << "Enter elements of the " << i + 1 << "st row:" << std::endl;
		*(*arr + i) = new int[n];
		for (int j = 0; j < n; j++) {
			std::cin >> *(*(*arr + i) + j);
		}
	}
}

void print_2d_arr(int*** arr, int m, int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << *(*(*arr + i) + j) << " ";
		}
		std::cout << std::endl;
	}
}

void process_array(int*** arr, int m, int n, int*** dest_arr) 
{
	int counter;
	for (int i = 0; i < m; i++) {
		*(*dest_arr + i) = new int[(n / 2)];
		counter = 0;
		for (int j = 0; j < n; j++) {
			if (j % 2 == 0) {
				*(*(*dest_arr + i) + counter) = *(*(*arr + i) + j);
				counter++;
			}
		}
	}
}

void delete_2d_arr(int*** arr, int m, int n) {
	for (int i = 0; i < m; i++) {
		delete[] *(*arr + i);
	}
	delete[] (*arr);
}


int main()
{
	int m, n;
	std::cout << "Enter rows count: ";
	std::cin >> m;
	std::cout << "Enter cols count: ";
	std::cin >> n;

	int** arr = new int*[m];
	read_2d_arr(&arr, m, n);

	int** new_arr = new int*[m];
	process_array(&arr, m, n, &new_arr);


	std::cout << "Result: " << std::endl;
	print_2d_arr(&new_arr, m, n / 2);

	delete_2d_arr(&arr, m, n);
	delete_2d_arr(&new_arr, m, n / 2);
	return 0;
}	
