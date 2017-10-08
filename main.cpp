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
	cout << "������ ��� �������� ���������� ����������." << endl;
}

void show_array(int *array, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "array[" << i << "]" << ":\t" << array[i] << endl;
	}
}

int* create_array(int &n)
{
	cout << "������� ���������� ��������� � ������������� �������: ";
	cin >> n;
	
	while(n <= 0)
	{
		cout << "���������� ��������� ������� �� ����� ���� ������ ������! ���������: ";
		cin >> n;
	}

	int* array = new int[n];
	
	for	(int i = 0; i < n; i++) array[i] = 0;

	cout << "������ ������ �� " << n << " ��������� ������." << endl;
	
	return array;
}

void show_menu()
{
printf("\n�������� ��������:\n\
1) ������� ������.\n\
2) ������� ���������� ������� �� �������.\n\
3) ��������� ������ ���������� ����������.\n\
4) �����.\n");
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
					cout << "��� ������ ������ ���������� �������!" << endl;
				break;
			case 3:
				if (array != nullptr)
					randomize_array(array, n);
				else
					cout << "��� ������ ������ ���������� �������!" << endl;
				break;
			case 4: 
				done = true;
				break;
		}
	}
	
	return 0;
}