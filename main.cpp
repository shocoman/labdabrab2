#include <iostream>
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

	cout << "������ �� " << n << " ��������� ������." << endl;
	
	return array;
}

void show_menu()
{
printf("�������� ��������:\n\
1) ������� ������ � ����.\n\
2) ������� ���������� ������� �� �������.\n\
3) ��������� ������ ���������� ����������.\n\
4) ��������� ���� ������ ���������� � ����������.\n\
5) �������� ���� �������� � ������� �� �������� � ����������.\n\
6) ����� ��� ���������� ������������� �������� �������.\n\
7) �����.\n");
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