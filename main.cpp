#include <iostream>
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

	cout << "Массив на " << n << " элементов создан." << endl;
	
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

				break;
			case 3: 

				break;
			case 4: 

				break;
			case 5:

				break;
			case 6: 

				break;
			case 7: 
				done = true;
				break;
		}
	}
	
	return 0;
}