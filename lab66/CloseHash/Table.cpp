#include "hash.h"
#include <ctime>

// ����� �� �������� ���������
// ��������, ���������� � ���������� �������� ����������� �� O(1)
// �� ����� � ���, ��� ������ ������� ���������� � �� �������� ����������� ����������� ��� ���������� ��������, 70% ����������

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));
	Contact* hashTable[SIZE2];
	string str;
	int value;
	Contact a;
	Contact* temp;
	int count = 0;

	for (int i = 0; i < SIZE2; i++) {
		hashTable[i] = nullptr;
	}
	for (int i = 0; i < 20; i++) {

		a.fio = "BAB";
		a.number = rand()%32757;
		add_elem(a, hashTable);
		count++;
	}
	print_table(hashTable);
	do
	{
		cin >> value;
		if (value == 0) {
			break;
		}
		del_elem(value, hashTable, count);
	} while (value != 0);



	cin >> value;
	temp = search_elem(value, hashTable, count);
	if (temp == nullptr) {
		cout << "������� �� ������" << endl;
	}
	else {
		cout << "������� ������\n�������: " << temp->fio << endl << "�����: " << temp->number << endl;
	}


	cout << "aslkjgkasjg" << endl;
	return 0;
}