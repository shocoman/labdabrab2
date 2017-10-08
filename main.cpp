#include <iostream>
using namespace std;

void show_array(int *array, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "array[" << i << "]" << ":\t" << array[i] << endl;
	}
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
printf("\nВыберите действие:\n\
1) Создать массив.\n\
2) Вывести содержимое массива на консоль.\n\
3) Выйти.\n");
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
					show_array(array, n);
				else
					cout << "Для начала массив необходимо создать!" << endl;
				break;
			case 3:
				done = true;
				break;
		}
	}
	
	return 0;
}