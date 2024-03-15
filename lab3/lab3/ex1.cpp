#include <iostream>
#include <ctime>
#include <vector>
#include <chrono>
using namespace std;

void bubble(vector<int>&, int); // Передаем массивы по ссылке, чтобы они изменяли не только в самой функции, но и во всей программе
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

	for (int i = 0; i < size; i++) { // Вводим рандомные значения в наш основной массив
		arr[i] = rand() % 100 + 1;
	}

	// Копируем значения из основного массива в массивы под каждую сортировку
	copy(arr.begin(), arr.end(), bubbleArr.begin());
	copy(arr.begin(), arr.end(), pastArr.begin());
	copy(arr.begin(), arr.end(), shellArr.begin());
	copy(arr.begin(), arr.end(), selectArr.begin());
	copy(arr.begin(), arr.end(), fastArr.begin());


	auto start_value = chrono::high_resolution_clock::now(); // Начало записи времени
	bubble(bubbleArr, size);
	auto end_value = chrono::high_resolution_clock::now(); // Конец записи времени
	chrono::duration<double, nano> difference_value = end_value - start_value; // Вычилсение времени путем арифметики.
	// В дальнейшем будут выполняться такие же действия только с разными функциями.
	for (int i = 0; i < size; i++) {
		cout << bubbleArr[i] << ' ';
	} // Вывод отсортированного массива на экран
	cout << "\nПузырьковая сортировка: " << difference_value.count() <<" наносекунд\n" << endl; // Вывод времени выполнения в наносекундах

	// Сортировка вставками
	start_value = chrono::high_resolution_clock::now();
	past(pastArr, size);
	end_value = chrono::high_resolution_clock::now();
	difference_value = end_value - start_value;
	for (int i = 0; i < size; i++) { // Вывод отсортированного массива
		cout << pastArr[i] << ' ';
	}
	cout << "\nСортировка вставками: " << difference_value.count() << " наносекунд\n" << endl;

	// Сортировка Шелла
	start_value = chrono::high_resolution_clock::now();
	shell(shellArr, size);
	end_value = chrono::high_resolution_clock::now();
	difference_value = end_value - start_value;
	for (int i = 0; i < size; i++) { // Вывод отсортированного массива
		cout << shellArr[i] << ' ';
	}
	cout << "\nСортировка Шелла: " << difference_value.count() << " наносекунд\n" << endl;

	// Быстрая сортировка
	start_value = chrono::high_resolution_clock::now();
	fast(fastArr, 0, size - 1);
	end_value = chrono::high_resolution_clock::now();
	difference_value = end_value - start_value;
	for (int i = 0; i < size; i++) { // вывод отсортированного массива
		cout << fastArr[i] << ' ';
	}
	cout << "\nБыстрая сортировка: " << difference_value.count() << " наносекунд\n" << endl;

	// Сортировка выбором
	start_value = chrono::high_resolution_clock::now();
	select(selectArr, size);
	end_value = chrono::high_resolution_clock::now();
	difference_value = end_value - start_value;
	for (int i = 0; i < size; i++) { // Вывод отсортированного массива
		cout << selectArr[i] << ' ';
	}
	cout << "\nСортировка выбором: " << difference_value.count() << " наносекунд\n" << endl;

	return 0;
}

void bubble(vector<int>& arr, int size) {
	int temp = 0; // Переменная для того, чтобы в дальнейшем переставить элементы местами

	for (int i = 0; i < size - 1; i++){ // Цикл выполняем до предпоследнего элемента, т.к у него нет соседа справа(для того, чтобы небыло выхода за пределы)
		for (int j = 0; j < size - i - 1; j++) { // Т.к мы отсортировали один элемент( по итоги первого цикла максимальный элемент находится справа), для уменьшение иттераций уменьшаем значение на 1
			if (arr[j] > arr[j + 1]) { // Сравниваем рядомстоящие элементы, если текущий элемент больше следующего, то меняем их местами
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void past(vector<int>& arr, int size) {
	int temp, j;

	for (int i = 1; i < size; i++) { // Начинаем проходку со 2 элемента массива
		temp = arr[i]; // Берем наше значение во временную переменную для того, чтобы вставить данное значение в правильное место
		j = i - 1; // При первой итерации захватываем первый элемент для сравненияы
		while (j >= 0 && arr[j] > temp) { // Ищем место, куда можно вставить наше значение
			arr[j + 1] = arr[j]; // Сдвигаем каждый элемент в массиве вправо, т.к число вставиться в нужно место
			j--;
		}
		arr[j + 1] = temp; // После прошлого цикла вставляем наше записанное значение в правильное место
	}
}


void shell(vector<int>& arr, int size) {
	int temp;
	for (int gap = size / 2; gap > 0; gap /= 2) { // Указываем расстояние между элементами и при каждой итерации уменьшаем его в 2 раза
			for (int i = gap; i < size; i++) { // Данный цикл предназначен для того, чтобы проверить каждый подмассив значений
				for (int j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap) { // Если находится число (через шаг), меньшее текущему числу, то меняем местами, при этом от j отнимаем шаг
					temp = arr[j]; // Меняем позицию текущего элемента с элементом, расположенным на каком-то шаге от текущего
					arr[j] = arr[j + gap];
					arr[j + gap] = temp;
				}
			}
	}
}

void select(vector<int>& arr, int size) {
	int min, temp; // Объявление переменных для минимального значения и временного

	for (int i = 0; i < size - 1; i++) {
		min = i; // Предполагаем, что текущий элемент является минимальным

		for (int j = i + 1; j < size; j++) // С помощью данного цикла находим минимальный элемент массива
			if (arr[j] < arr[min])
				min = j; // Обновляем индекс минимального элемента

			if (i!= min) { // Если минимальный элемент не стоит на нужном месте, то меняем значения местами
				temp = arr[i];
				arr[i] = arr[min];
				arr[min] = temp;
			}
	}
}

void fast(vector<int>& arr, int left, int right) { // В функцию должны передаваться индекс первого элемента и последнего. Это нужно для того, чтобы указатели шли от начала к концу и наоборот

	if (left >= right)// Это условие предназначено для рекурсивных алгоритмов. Для того, чтобы он завершился без ошибки.
		return;

	int temp; // Переменная для дальнейшей перестановки
	int i = left; // Ставим указатели на начало и на конец массива
	int j = right;

	int mid = arr[(i + j) / 2]; // Выбираем опорный элемент(в моем случае это элемент, находящийся посередине)

	while (i <= j) { // Проходим до того момента, пока указатель на начальное значение не будет больше указателя на конечное значение
		while (arr[i] < mid) // Находим число, большее чем опорный элемент слева от него
			i++;
		while (arr[j] > mid) // Находим число, меньшее чем опорный элемент справа от него
			j--;
		if (i <= j) {
			temp = arr[i]; // Меняем местами нашедшие элементы
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}

	fast(arr, left, j); // Рекурсивно заходим в функцию, чтобы отсортировать левый подмассив
	fast(arr, i, right);// Рекурсивно заходим в функцию, чтобы отсортировать правый подмассив
}
