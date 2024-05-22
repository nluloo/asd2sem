#pragma once

#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#define SIZE1 16
#define SIZE2 32
#define SIZE3 128
#define INT_MAX 32767

struct Contact {
	int number;
	string fio;
};

int calcul_hash(int value);
void add_elem(Contact elem, Contact**);
void del_elem(int value, Contact**, int);
Contact* search_elem(int value, Contact**, int);
void print_table(Contact**);