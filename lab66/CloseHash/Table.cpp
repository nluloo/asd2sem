#include "hash.h"
#include <ctime>

// Здесь же закрытая адресация
// Удаление, добавление и нахождение элемента происходить за O(1)
// Но минус в том, что данная таблица ограничена и ее придется динамически увеличивать при достижении например, 70% заполнения

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
		cout << "Элемент не найден" << endl;
	}
	else {
		cout << "Элемент найден\nФамилия: " << temp->fio << endl << "Номер: " << temp->number << endl;
	}


	cout << "aslkjgkasjg" << endl;
	return 0;
}