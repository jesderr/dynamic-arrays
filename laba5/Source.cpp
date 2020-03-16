#include <time.h>
#include <iostream>

void random(int**& array, int row_size, int col_size)
{
	srand(time(NULL));
	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < col_size; j++)
		{
			array[i][j] = rand() % 100 - 50;
		}
	}
}

void print(int**& array, int row_size, int col_size)
{
	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < col_size; j++)
		{
			std::cout << array[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void search(int**& array, int row_size, int col_size)
{
	int max = INT_MIN;
	int min = INT_MAX;
	for (int j = col_size - 2; j < col_size; j++)
	{
		for (int i = 0; i < row_size; i++)
		{
			if (array[i][j] < min)
			{
				min = array[i][j];
			}
		}
	}
	std::cout << "min=" << min << std::endl;


	for (int i = row_size - 2; i < row_size; i++)
	{
		for (int j = 0; j < col_size; j++)
		{
			if (array[i][j] > max)
			{
				max = array[i][j];
			}
		}
	}
	std::cout << "max=" << max << std::endl;
}

void change(int**& array, int row_size, int col_size)
{
	for (int i = 0; i < row_size; i++)
	{
		int min = INT_MAX;
		int max = INT_MIN;
		int min_j = 0;
		int max_j = 0;
		for (int j = 0; j < col_size; j++)
		{
			if (array[i][j] < min)
			{
				min = array[i][j];
				min_j = j;
			}
			if (array[i][j] > max)
			{
				max = array[i][j];
				max_j = j;
			}
		}
		//std::cout << "min = " << min << std::endl;
		//std::cout << "max = " << max << std::endl;
		int t = array[i][max_j];
		array[i][max_j] = array[i][min_j];
		array[i][min_j] = t;
	}
}

void sun_and_mult()
{
	const int n = 5;
	int* Arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cout << "Arr[i]=";
		std::cin >> Arr[i];
	}
	int sum = 0;
	int mult = 1;
	int first_positive_number = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (Arr[i] > 0 && first_positive_number == INT_MAX)
		{
			first_positive_number = i;
		}
		if (first_positive_number < i)
		{
			sum += Arr[i];
			mult *= Arr[i];
		}
	}
	std::cout << "sum=" << sum << std::endl;
	std::cout << "mult=" << mult << std::endl;
	delete[] Arr;
}

int main() 
{
	sun_and_mult();
	//const int str = 5, stl = 5;
	//int** array = new int*[str];
	//for (int i = 0; i < str; i++) {
	//	array[i] = new int[stl];
	//}
	//random(array, str, stl);
	//print(array, str, stl);
	//search(array, str, stl);
	//change(array, str, stl);
	//std::cout << "\n\n\n" << std::endl;
	//print(array, str, stl);

	//for (int i = 0; i < str; i++) {
	//	delete[] array[i];
	//}
	//delete[] array;
	return 0;
}