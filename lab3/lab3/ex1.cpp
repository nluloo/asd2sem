#include <iostream>
#include <ctime>
#include <vector>
#include <chrono>
using namespace std;

void bubble(vector<int>&, int); // �������� ������� �� ������, ����� ��� �������� �� ������ � ����� �������, �� � �� ���� ���������
void past(vector<int>&, int);
void select(vector<int>&, int);
void fast(vector<int>&, int, int);
void shell(vector<int>&, int);

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));

	int size;

	cin >> size;

	vector<int> arr(size);
	vector<int> bubbleArr(size);
	vector<int> pastArr(size);
	vector<int> shellArr(size);
	vector<int> selectArr(size);
	vector<int> fastArr(size);

	for (int i = 0; i < size; i++) { // ������ ��������� �������� � ��� �������� ������
		arr[i] = rand() % 100 + 1;
	}

	// �������� �������� �� ��������� ������� � ������� ��� ������ ����������
	copy(arr.begin(), arr.end(), bubbleArr.begin());
	copy(arr.begin(), arr.end(), pastArr.begin());
	copy(arr.begin(), arr.end(), shellArr.begin());
	copy(arr.begin(), arr.end(), selectArr.begin());
	copy(arr.begin(), arr.end(), fastArr.begin());


	auto start_value = chrono::high_resolution_clock::now(); // ������ ������ �������
	bubble(bubbleArr, size);
	auto end_value = chrono::high_resolution_clock::now(); // ����� ������ �������
	chrono::duration<double, nano> difference_value = end_value - start_value; // ���������� ������� ����� ����������.
	// � ���������� ����� ����������� ����� �� �������� ������ � ������� ���������.
	for (int i = 0; i < size; i++) {
		cout << bubbleArr[i] << ' ';
	} // ����� ���������������� ������� �� �����
	cout << "\n����������� ����������: " << difference_value.count() <<" ����������\n" << endl; // ����� ������� ���������� � ������������

	// ���������� ���������
	start_value = chrono::high_resolution_clock::now();
	past(pastArr, size);
	end_value = chrono::high_resolution_clock::now();
	difference_value = end_value - start_value;
	for (int i = 0; i < size; i++) { // ����� ���������������� �������
		cout << pastArr[i] << ' ';
	}
	cout << "\n���������� ���������: " << difference_value.count() << " ����������\n" << endl;

	// ���������� �����
	start_value = chrono::high_resolution_clock::now();
	shell(shellArr, size);
	end_value = chrono::high_resolution_clock::now();
	difference_value = end_value - start_value;
	for (int i = 0; i < size; i++) { // ����� ���������������� �������
		cout << shellArr[i] << ' ';
	}
	cout << "\n���������� �����: " << difference_value.count() << " ����������\n" << endl;

	// ������� ����������
	start_value = chrono::high_resolution_clock::now();
	fast(fastArr, 0, size - 1);
	end_value = chrono::high_resolution_clock::now();
	difference_value = end_value - start_value;
	for (int i = 0; i < size; i++) { // ����� ���������������� �������
		cout << fastArr[i] << ' ';
	}
	cout << "\n������� ����������: " << difference_value.count() << " ����������\n" << endl;

	// ���������� �������
	start_value = chrono::high_resolution_clock::now();
	select(selectArr, size);
	end_value = chrono::high_resolution_clock::now();
	difference_value = end_value - start_value;
	for (int i = 0; i < size; i++) { // ����� ���������������� �������
		cout << selectArr[i] << ' ';
	}
	cout << "\n���������� �������: " << difference_value.count() << " ����������\n" << endl;

	return 0;
}

void bubble(vector<int>& arr, int size) {
	int temp = 0; // ���������� ��� ����, ����� � ���������� ����������� �������� �������

	for (int i = 0; i < size - 1; i++){ // ���� ��������� �� �������������� ��������, �.� � ���� ��� ������ ������(��� ����, ����� ������ ������ �� �������)
		for (int j = 0; j < size - i - 1; j++) { // �.� �� ������������� ���� �������( �� ����� ������� ����� ������������ ������� ��������� ������), ��� ���������� ��������� ��������� �������� �� 1
			if (arr[j] > arr[j + 1]) { // ���������� ������������ ��������, ���� ������� ������� ������ ����������, �� ������ �� �������
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void past(vector<int>& arr, int size) {
	int temp, j;

	for (int i = 1; i < size; i++) { // �������� �������� �� 2 �������� �������
		temp = arr[i]; // ����� ���� �������� �� ��������� ���������� ��� ����, ����� �������� ������ �������� � ���������� �����
		j = i - 1; // ��� ������ �������� ����������� ������ ������� ��� ����������
		while (j >= 0 && arr[j] > temp) { // ���� �����, ���� ����� �������� ���� ��������
			arr[j + 1] = arr[j]; // �������� ������ ������� � ������� ������, �.� ����� ���������� � ����� �����
			j--;
		}
		arr[j + 1] = temp; // ����� �������� ����� ��������� ���� ���������� �������� � ���������� �����
	}
}


void shell(vector<int>& arr, int size) {
	int temp;
	for (int gap = size / 2; gap > 0; gap /= 2) { // ��������� ���������� ����� ���������� � ��� ������ �������� ��������� ��� � 2 ����
			for (int i = gap; i < size; i++) { // ������ ���� ������������ ��� ����, ����� ��������� ������ ��������� ��������
				for (int j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap) { // ���� ��������� ����� (����� ���), ������� �������� �����, �� ������ �������, ��� ���� �� j �������� ���
					temp = arr[j]; // ������ ������� �������� �������� � ���������, ������������� �� �����-�� ���� �� ��������
					arr[j] = arr[j + gap];
					arr[j + gap] = temp;
				}
			}
	}
}

void select(vector<int>& arr, int size) {
	int min, temp; // ���������� ���������� ��� ������������ �������� � ����������

	for (int i = 0; i < size - 1; i++) {
		min = i; // ������������, ��� ������� ������� �������� �����������

		for (int j = i + 1; j < size; j++) // � ������� ������� ����� ������� ����������� ������� �������
			if (arr[j] < arr[min])
				min = j; // ��������� ������ ������������ ��������

			if (i!= min) { // ���� ����������� ������� �� ����� �� ������ �����, �� ������ �������� �������
				temp = arr[i];
				arr[i] = arr[min];
				arr[min] = temp;
			}
	}
}

void fast(vector<int>& arr, int left, int right) { // � ������� ������ ������������ ������ ������� �������� � ����������. ��� ����� ��� ����, ����� ��������� ��� �� ������ � ����� � ��������

	if (left >= right)// ��� ������� ������������� ��� ����������� ����������. ��� ����, ����� �� ���������� ��� ������.
		return;

	int temp; // ���������� ��� ���������� ������������
	int i = left; // ������ ��������� �� ������ � �� ����� �������
	int j = right;

	int mid = arr[(i + j) / 2]; // �������� ������� �������(� ���� ������ ��� �������, ����������� ����������)

	while (i <= j) { // �������� �� ���� �������, ���� ��������� �� ��������� �������� �� ����� ������ ��������� �� �������� ��������
		while (arr[i] < mid) // ������� �����, ������� ��� ������� ������� ����� �� ����
			i++;
		while (arr[j] > mid) // ������� �����, ������� ��� ������� ������� ������ �� ����
			j--;
		if (i <= j) {
			temp = arr[i]; // ������ ������� �������� ��������
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}

	fast(arr, left, j); // ���������� ������� � �������, ����� ������������� ����� ���������
	fast(arr, i, right);// ���������� ������� � �������, ����� ������������� ������ ���������
}
