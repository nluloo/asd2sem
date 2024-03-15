#include <iostream>
#include <chrono>

using namespace std;

unsigned long long recursive_counting(int);

int main() {
    setlocale(LC_ALL, "ru");
    int N, i = 2; // По условию номер числа последовательности Фибоначчи(N) пользователь вводит с клавиатуры
    // i присваиваем 2 т.к у нас изначально даны 2 первых числа (0 и 1)
    unsigned long long fFirst = 0, fSecond = 1, fn = 0;
    cout << "Введите номер числа последовательности: ";
    cin >> N;

    cout << "While: " << endl;
    auto start_value = chrono::high_resolution_clock::now();
    while (i < N) {
        fn = fFirst + fSecond;
        fFirst = fSecond;
        fSecond = fn;
        i++;
    }
    cout << fn << endl;
    auto end_value = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> difference_value = end_value - start_value;
    cout << difference_value.count() << " seconds" << endl;

    cout << "Recursive: " << endl;
    start_value = chrono::high_resolution_clock::now();
    cout << recursive_counting(N) << endl;
    end_value = chrono::high_resolution_clock::now();

    difference_value = end_value - start_value;

    cout << difference_value.count() << " seconds" << endl;

    return 0;
}

unsigned long long recursive_counting(int n) {
    if (n == 1)
        return 0;
    if (n == 2 || n == 3) // Второй и третий жлемент последовательности 1
        return 1;

    return recursive_counting(n - 1) + recursive_counting(n - 2);
}
