#include <iostream>

using namespace std;

int main() {
	int highLimit, lowerLimit = 1, steps = 0;
	unsigned long long N;
	int choise;

	cout << "Enter the number: ";
	cin >> N;

	while (lowerLimit <= N)
	{
		highLimit = (lowerLimit + N) / 2;
		steps++;
		cout << highLimit << "\n1.Few\n2.Many\n3.Guessed" << endl;
		cin >> choise;

		switch (choise)
		{
		case 1:
			lowerLimit = highLimit + 1;
			break;
		case 2:
			N = highLimit - 1;
			break;
		case 3:
			cout << "Amount steps: " << steps << endl;
			return 0;
		default:
			break;
		}
	}
	return 0;
}