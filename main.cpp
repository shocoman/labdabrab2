#include "stdafx.h"
#include <iostream>
#include <random>
#include <time.h>
#include <Windows.h>
using namespace std;

void randomize_array(int *array, int n)
{
	srand(time(NULL) + rand() % 50);
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 2000 - 1000;
	}
	cout << "The array was filled with random numbers." << endl;
}

void show_array(int *array, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "array[" << i << "]" << ":\t" << array[i] << endl;
	}
}

void swap(int &a, int &b)
{
	int temp = a;
	
	a = b;
	b = temp;
}

int* copy_array(int *array, int n)
{
	int *new_array = new int[n];
	for (int i = 0; i < n; i++)
	{
		new_array[i] = array[i];
	}
	
	return new_array;
}

int* create_array(int &n)
{
	cout << "Enter the number of elements in an integer array: ";
	cin >> n;
	
	while(n <= 0)
	{
		cout << "The number of array elements can not be less than one! Please repeat: ";
		cin >> n;
	}

	int* array = new int[n];
	
	for	(int i = 0; i < n; i++) array[i] = 0;

	cout << "Empty array on " << n << " cells created." << endl;
	
	return array;
}

void show_menu()
{
printf("Select an action:\n\
1) Create an array.\n\
2) Output the contents of the array to the console.\n\
3) Fill the array with random values.\n\
4) Fill the all array with values from the keyboard.\n\
5) Replace one value in the array with one entered from the keyboard.\n\
6) Find the three least positive elements of an array.\n\
7) Exit.\n");
}

int main(int argc, char **argv)
{
	//SetConsoleCP(65001);					//Coding for Russian output in the console	
	//SetConsoleOutputCP(65001);

	int* array = nullptr;
	int* array_copy = nullptr;
	int n;
	
	int choice;
	bool done = false;
	
	do {
		show_menu();

		cin >> choice;

		cout << endl;

		switch (choice)
		{
			case 1: 
				if (array != nullptr)
				{
					delete[] array;
					array = nullptr;
				}
				array = create_array(n);

				break;

			case 2: 
				if (array != nullptr)
					show_array(array, n);
				else
					cout << "First you need to create an array!" << endl;

				break;

			case 3:
				if (array != nullptr)
					randomize_array(array, n);
				else
					cout << "First you need to create an array!" << endl;

				break;

			case 4:
				if (array != nullptr)
				{
					for (int i = 0; i < n; i++)
					{
						cout << "array[" << i << "]" << " will be: ";
						cin >> array[i];
					}
					cout << "The array was completely filled." << endl;
				}
				else
					cout << "First you need to create an array!" << endl;

				break;

			case 5:
				int j,k;
				if (array != nullptr)
				{
					cout << "Enter the number of the element you want to change and what for: ";
					cin >> j >> k;
					while (j < 0 || j >= n)
					{
						cout << "There is no such element of the array. Please repeat: ";
						cin >> j >> k;
					}
					array[j] = k;
					printf("%i an array element was assigned a value %i", j,k);
				}
				else
					cout << "First you need to create an array!" << endl;		

				break;

			case 6:
				if (array != nullptr)
				{
					array_copy = copy_array(array, n);
					int a, b, c;
					
					for (int i = 0; i < 3; i++)
					{
						for (int j = n-1; j > 0; j--)
						{
							if ((array_copy[j] > 0) && ((array_copy[j] <= array_copy[j-1]) ||
								(array_copy[j] > array_copy[j-1] && array_copy[j-1] <= 0)))
							{
								swap(array_copy[j], array_copy[j-1]);
							}
						}
					}
					if (array_copy[2] > 0)
					{
						for (int i = 0; i < n; i++)
						{
							if (array[i] == array_copy[0]) a = i;
							if (array[i] == array_copy[1]) b = i;
							if (array[i] == array_copy[2]) c = i;
						}
						printf("array[%i]: %i\narray[%i]: %i\narray[%i]: %i\n\n", a, array_copy[0], b, array_copy[1], c, array_copy[2]);
					}
					else 
					{
						cout << "There are not enough positive elements in the array." << endl;
					}
					
					delete[] array_copy;
				}
				else
					cout << "First you need to create an array!" << endl;					
				break;

			case 7: 
				done = true;

				break;
		}
	} while(!done);
	
	return 0;
}