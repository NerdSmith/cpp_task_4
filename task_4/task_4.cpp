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

//void process_array(int*** arr, int m, int n, int*** dest_arr) // removes elements 
//{
//	int counter;
//	for (int i = 0; i < m; i++) {
//		*(*dest_arr + i) = new int[(n / 2)];
//		counter = 0;
//		for (int j = 0; j < n; j++) {
//			if (j % 2 == 0) {
//				*(*(*dest_arr + i) + counter) = *(*(*arr + i) + j);
//				counter++;
//			}
//		}
//	}
//}

int* copy_2d_arr_line(int* arr, int n) {
	int* line_copy = new int [n];
	for (int i = 0; i <= n; i++) {
		*(line_copy + i) = *(arr + i);
	}
	return line_copy;
}

void process_array(int*** arr, int m, int n, int*** dest_arr) // removes lines
{
	int counter = 0;
	for (int i = 0; i < m; i++) {
		//if (i % 2 != 0) {
		//	*(*dest_arr + counter) = *(*arr + i);
		//	counter++;
		//}
		// or
		if (i % 2 != 0) {
			*(*dest_arr + counter) = copy_2d_arr_line(*(*arr + i), n);
			counter++;
		}
	}
}

void delete_2d_arr(int*** arr, int m, int n) {
	for (int i = 0; i < m; i++) {
		delete[] * (*arr + i);
	}
	delete[](*arr);
}

void delete_self_2d_arr(int*** arr, int m, int n) {
	delete[](*arr);
}


int main()
{
	int m, n;
	std::cout << "Enter rows count: ";
	std::cin >> m;
	std::cout << "Enter cols count: ";
	std::cin >> n;

	int** arr = new int* [m];
	read_2d_arr(&arr, m, n);

	// int** new_arr = new int* [m];
	int** new_arr = new int* [m / 2];
	process_array(&arr, m, n, &new_arr);

	std::cout << "Result: " << std::endl;
	// print_2d_arr(&new_arr, m, n / 2);
	print_2d_arr(&new_arr, m / 2, n);

	delete_2d_arr(&arr, m, n);
	// delete_self_2d_arr(&new_arr, m / 2, n);
	// delete_2d_arr(&new_arr, m, n / 2);
	delete_2d_arr(&new_arr, m / 2, n);
	return 0;
}
