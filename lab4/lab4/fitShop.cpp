#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

void bubble(vector<int>& B, int N) {
	int i, j;
	for (i = 0; i < N - 1; i++) {
		for (j = 0; j < N - i - 1; j++) {
			if (B[j] > B[j + 1]) {
				swap(B[j], B[j + 1]);
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));

	int shops;
	cin >> shops;
	
	vector<int> sposs(shops);
	vector<int> idsposs(shops);

	for (int i = 0; i < shops; i++) {
		sposs[i] = rand() % 100 + 1;
		idsposs[i] = sposs[i];
	}

	for (int i = 0; i < shops; i++) {
		cout << sposs[i] << ' ';
	}
	cout << endl;

	bubble(idsposs, shops);
	for (int i = 0; i < shops; i++) {
		cout << idsposs[i] << ' ';
	}
	cout << endl;

	int g = 1; // переменная отвечающая за позицию четного числа
	int min = sposs[0];
	for (int i = 0; i < shops / 2 ; i++) { // Алгоритм говно, если поподается 2 одинаковые цены, то все, gg wp
		for (int j = 0; j < shops; j++) {
			if (idsposs[i] == sposs[j]) {
				if (i >= 1 && idsposs[i] == idsposs[i - 1] && j == g - 2) { // теперь не говно. Если находим равные элементы( в отсортированном массиве они будут стоять рядом), то проверяем их с позицией числа, стоящего уже на месте четного
					// Если он там стоит, то пропускаем шаг, чтобы в массиве найти другой элемент с этим же значением.
					continue;
				}
				swap(sposs[j], sposs[g]);
				g += 2;
				break;
			}
		}
	}// Алгоритм все равно говно, т.к если попадется уже 3 одинаковых цены, то плак плак, опять все ломается

	for (int i = 0; i < shops; i++) {
		cout << sposs[i] << ' ';
	}
	cout << endl;

	int sum = 0;
	for (int i = 0; i < shops; i++) {
		if ((i + 1) % 2 != 0) {
			sum += sposs[i];
		}
	}
	cout << "Max price: " << sum << endl;
	return 0;
}
