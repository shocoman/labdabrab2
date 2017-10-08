#include <iostream>
#include <random>
#include <time.h>
using namespace std;

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
printf("\nВыберите действие:\n\
1) Создать массив.\n\
2) Заполнить весь массив значениями с клавиатуры.\n\
3) Заменить одно значение в массиве на введённое с клавиатуры.\n\
4) Выйти.\n");
}

int main(int argc, char **argv)
{
	setlocale(LC_CTYPE, "rus");
	
	int* array = nullptr;
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
			case 3:
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
			case 4: 
				done = true;
				break;
		}
	}
	
	return 0;
}