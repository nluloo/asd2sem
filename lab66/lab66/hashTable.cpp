#include "hash.h"
#include <ctime>
#include <chrono>

// Таблица с открытой адресацией
// Минус в том что добавление и удаление происходят за O(n) - в худшем случае

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
				cout << "Введите ФИО добавляемого контакта: " << endl;
				a.fio = "Сегренёв Кирилл Сергеевич";
				cout << "Введите номер контакта: " << endl;
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
				cout << "Введите номер удаляемого контакта: " << endl;
				cin >> value;
				if (value == 0) {
					break;
				}
				del_elem(value, hashTable);
			} while (value != 0);
			break;
		case 4:
			cout << "Введите номер для поиска контакта: " << endl;
			cin >> value;
			startTime = chrono::high_resolution_clock::now();
			temp = search_elem(value, hashTable);
			endTime = chrono::high_resolution_clock::now();
			chrono::duration<double, nano> difference = endTime - startTime;
			if (temp == nullptr) {
				cout << "Элемент не найден" << endl;
			}
			else {
				cout << "Элемент найден\nФамилия: " << temp->fio << endl << "Номер: " << temp->number << endl;
			}
			cout << "Время, затраченное для поиска элемента: " << difference.count() << " наносекунд" << endl;

			break;
		default:
			break;
		}
	} while (choice != 0);
	return 0;
}