#include <iostream>
#include <random>
#include <time.h>
using namespace std;

void randomize_array(int *array, int n)
{
	srand(time(NULL) + rand() % 50);
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 2000 - 1000;
	}
	cout << "Массив был заполнен случайными значениями." << endl;
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
	cout << "Введите количество элементов в целочисленном массиве: ";
	cin >> n;
	
	while(n <= 0)
	{
		cout << "Количество элементов массива не может быть меньше одного! Повторите: ";
		cin >> n;
	}

	int* array = new int[n];
	
	for	(int i = 0; i < n; i++) array[i] = 0;

	cout << "Пустой массив на " << n << " элементов создан." << endl;
	
	return array;
}

void show_menu()
{
printf("Выберите действие:\n\
1) Создать массив с нуля.\n\
2) Вывести содержимое массива на консоль.\n\
3) Заполнить массив случайными значениями.\n\
4) Заполнить весь массив значениями с клавиатуры.\n\
5) Заменить одно значение в массиве на введённое с клавиатуры.\n\
6) Найти три наименьших положительных элемента массива.\n\
7) Выйти.\n");
}

int main(int argc, char **argv)
{
	setlocale(LC_CTYPE, "rus");
	
	int* array = nullptr;
	int* array_copy = nullptr;
	int n;
	
	int choice;
	bool done = false;
	while(!done)
	{
		show_menu();
		cin >> choice;
		printf("\n");
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
					cout << "Для начала массив необходимо создать!" << endl;
				break;
			case 3:
				if (array != nullptr)
					randomize_array(array, n);
				else
					cout << "Для начала массив необходимо создать!" << endl;
			case 4:
				if (array != nullptr)
				{
					for (int i = 0; i < n; i++)
					{
						cout << "array[" << i << "]" << " будет равен: ";
						cin >> array[i];
					}
					cout << "Массив был полностью заполнен." << endl;
				}
				else
					cout << "Для начала массив необходимо создать!" << endl;
				break;
			case 5:
				int j,k;
				if (array != nullptr)
				{
					cout << "Значение какого элемента массива вы хотите поменять и на что: ";
					cin >> j >> k;
					while (j < 0 || j >= n)
					{
						cout << "Такого элемента массива не существует. Повторите: ";
						cin >> j >> k;
					}
					array[j] = k;
					printf("%i-му элементу массива было присвоено значение %i", j,k);
				}
				else
					cout << "Для начала массив необходимо создать!" << endl;					
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
						cout << "В массиве недостаточно положительных элементов." << endl;
					}
					
					delete[] array_copy;
				}
				else
					cout << "Для начала массив необходимо создать!" << endl;					
				break;
			case 7: 
				done = true;
				break;
		}
	}
	
	return 0;
}