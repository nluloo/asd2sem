#include "hash.h"

int calcul_hash(int value)
{
    int val = value;
    int hash = 0;
    for (int i = 1; val != 0; i++) {
        hash += (val % 10) * 31;
        val /= 10;
    }

    return hash % SIZE2;
}

void add_elem(Contact elem, Contact** arr)
{
    int hash = calcul_hash(elem.number);
    int id = 0;
    for (int i = 0; true; i++) {
        id = hash + i + pow(i, 2);
        id %= SIZE2;
        if (arr[id] == nullptr) {
            Contact* newElem = new Contact;
            newElem->fio = elem.fio;
            newElem->number = elem.number;
            arr[id] = newElem;
            return;
        }
    }
}

Contact* search_elem(int value, Contact** arr, int count)
{
    int hash = calcul_hash(value);
    int id;
    for (int i = 0; i < SIZE2; i++) {
        id = hash + i + pow(i, 2);
        id = id % SIZE2;
        if (arr[id] != nullptr && arr[id]->number == value) {
            return arr[id];
        }
    }
    return nullptr;
}

void del_elem(int value, Contact** arr, int count)
{
    int hash = calcul_hash(value);
    int id;
    for (int i = 0; i < SIZE2; i++) {
        id = hash + i + pow(i, 2);
        id %= SIZE2;
        if (arr[id] != nullptr && arr[id]->number == value) {
            Contact* temp = arr[id];
            delete temp;
            arr[id] = nullptr;
            return;
        }
    }
    cout << "Ёлемент не найден!" << endl;
}

void print_table(Contact** arr) {
    for (int i = 0; i < SIZE2; i++) {
        if (arr[i] == nullptr) {
            continue;
        }
        cout << i << ". " << arr[i]->fio << ' ' << arr[i]->number << endl;
    }
}


