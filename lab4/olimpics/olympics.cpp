#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

void qsort(vector<int>& arr, int low, int high);

int main() {
	srand(time(0));

	int amountPeoples;
	cin >> amountPeoples;
	vector<int> peoples(amountPeoples);
	vector<int> clonePeoples(amountPeoples);

	for (int i = 0; i < amountPeoples; i++) {
		peoples[i] = rand() % 100 + 1;
		clonePeoples[i] = peoples[i];
	}

	for (int i = 0; i < amountPeoples; i++) {
		cout << peoples[i] << ' ';
	}
	cout << endl;

	qsort(clonePeoples, 0, amountPeoples - 1); // ѕоигратьс€ с сортировками
	for (int i = 0; i < amountPeoples; i++) {
		cout << clonePeoples[i] << ' ';
	}
	cout << endl;
	
	int priz = 0; //  оличество участников, которые зан€ли призовые места
	int ogr = 3; // —тандартное количество человек, которые могут занимать призовые места
	for (int i = 0; i < ogr; i++) {
		if (clonePeoples[i] == clonePeoples[i + 1]) { // Ќаходим одинаковые баллы у участников.
			priz++;
			ogr++; // ”величивыаем количество призовых мест
			continue;
		}
		priz++;
	}
	cout << priz;

	return 0;
}

void qsort(vector<int>& arr, int low, int high) {
	if (low > high) {
		return;
	}
	int i = low;
	int j = high;
	int mid = arr[(low + high) / 2];
	while (i <= j) {
		while (arr[i] > mid) {
			i++;
		}
		while (arr[j] < mid)
		{
			j--;
		}
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
		
	}
	qsort(arr, low, j);
	qsort(arr, i, high);
}