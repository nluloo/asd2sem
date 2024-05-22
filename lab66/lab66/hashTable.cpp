#include "hash.h"
#include <ctime>
#include <chrono>

// ������� � �������� ����������
// ����� � ��� ��� ���������� � �������� ���������� �� O(n) - � ������ ������

using namespace std;

int main(){
	setlocale(LC_ALL, "ru");
	srand(time(0));
	Contact* hashTable[SIZE2];
	string str;
	int value, choice;
	Contact a;
	Contact* temp;
	chrono::steady_clock::time_point startTime, endTime;

	for (int i = 0; i < SIZE2; i++) {
		hashTable[i] = nullptr;
	}

	do
	{
		menu();
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			for (int i = 0; i < 100; i++) {
				cout << "������� ��� ������������ ��������: " << endl;
				a.fio = "������� ������ ���������";
				cout << "������� ����� ��������: " << endl;
				a.number = rand() % 32757;
				add_elem(a, hashTable);
			}
			break;
		case 2:
			print_table(hashTable);
			break;
		case 3:
			do
			{
				cout << "������� ����� ���������� ��������: " << endl;
				cin >> value;
				if (value == 0) {
					break;
				}
				del_elem(value, hashTable);
			} while (value != 0);
			break;
		case 4:
			cout << "������� ����� ��� ������ ��������: " << endl;
			cin >> value;
			startTime = chrono::high_resolution_clock::now();
			temp = search_elem(value, hashTable);
			endTime = chrono::high_resolution_clock::now();
			chrono::duration<double, nano> difference = endTime - startTime;
			if (temp == nullptr) {
				cout << "������� �� ������" << endl;
			}
			else {
				cout << "������� ������\n�������: " << temp->fio << endl << "�����: " << temp->number << endl;
			}
			cout << "�����, ����������� ��� ������ ��������: " << difference.count() << " ����������" << endl;

			break;
		default:
			break;
		}
	} while (choice != 0);
	return 0;
}