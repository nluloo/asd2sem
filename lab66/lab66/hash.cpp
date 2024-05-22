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
    Contact* newElem = new Contact;
    newElem->fio = elem.fio;
    newElem->number = elem.number;
    newElem->next = nullptr;

    if (arr[hash] != nullptr) {
        Contact* current = arr[hash];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newElem;
        newElem->last = current->next;
    }
    else {
        arr[hash] = newElem;
    }
}

void del_elem(int value, Contact** arr)
{
    int hash = calcul_hash(value);
    if (arr[hash] == nullptr) {
        cout << "Элемент не найден!" << endl;
        return;
    }
    else {
        Contact* temp = arr[hash];
        Contact* dell = temp->next;
        if (temp->number == value) {
            if (temp->next != nullptr) {
                arr[hash] = temp->next;
                delete temp;
                return;
            }
            else {
                delete temp;
                arr[hash] = nullptr;
                return;
            }
        }

        while (dell != nullptr && dell->number != value) {
            temp = dell;
            dell = temp->next;
        }
        if (dell == nullptr) return;
        temp->next = dell->next;
        delete dell;

    }
}

Contact* search_elem(int value, Contact** arr)
{
    int hash = calcul_hash(value);
    if (arr[hash] == nullptr) {
        return nullptr;
    }
    else {
        Contact* current = arr[hash];
        while (current != nullptr && current->number != value) {
            current = current->next;
        }
        return current;
    }
}
void print_table(Contact** arr) {
    Contact* temp = nullptr;
    int count = 1;
    std::cout << std::setw(10) << ' ' << "ФИО" << std::setw(25) << ' ' << "Номер телефона " << std::endl;
    std::cout << std::setfill('-') << std::setw(60) << "-" << std::endl;
    for (int i = 0; i < SIZE2; i++) {
        if (arr[i] == nullptr) {
            continue;
        }
        else {
            std::cout << count++ << ". " << std::setw(20) << std::left << arr[i]->fio << std::setw(5) << ' ' << std::setw(10) << std::setfill(' ') << arr[i]->number << std::endl;
            temp = arr[i]->next;
            while (temp != nullptr) {
                std::cout << count++ << ". " << std::setw(20) << std::left << arr[i]->fio << std::setw(5) << ' ' << std::setw(10) << std::setfill(' ') << arr[i]->number << std::endl;
                temp = temp->next;
            }
        }
    }
}


void menu() {
    cout << "1. Ввод элементо в хэш-таблицу" << endl;
    cout << "2. Вывод содержимого хэш-таблицы" << endl;
    cout << "3. Удаление элемента из хэш-таблицы" << endl;
    cout << "4. Поиск по номеру в хэш-таблице" << endl;
    cout << "0. Вызод из программы" << endl;
}
