#include <iostream>
#include <random>
#include <time.h>
using namespace std;

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
2) ��������� ���� ������ ���������� � ����������.\n\
3) �������� ���� �������� � ������� �� �������� � ����������.\n\
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
				{
					for (int i = 0; i < n; i++)
					{
						cout << "array[" << i << "]" << " ����� �����: ";
						cin >> array[i];
					}
					cout << "������ ��� ��������� ��������." << endl;
				}
				else
					cout << "��� ������ ������ ���������� �������!" << endl;
				break;
			case 3:
				int j,k;
				if (array != nullptr)
				{
					cout << "�������� ������ �������� ������� �� ������ �������� � �� ���: ";
					cin >> j >> k;
					while (j < 0 || j >= n)
					{
						cout << "������ �������� ������� �� ����������. ���������: ";
						cin >> j >> k;
					}
					array[j] = k;
					printf("%i-�� �������� ������� ���� ��������� �������� %i", j,k);
				}
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