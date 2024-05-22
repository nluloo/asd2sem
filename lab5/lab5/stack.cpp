#include <iostream>
#include <string>
struct MATH
{
	char a;
	MATH* next;
};
void push(char symb, MATH*& stack);
char pop(MATH*& myStk);

int main() {
	setlocale(LC_ALL, "ru");
	MATH* stack = new MATH;
	stack = NULL;
	std::string symb;

	std::getline(std::cin, symb);
	const char* tf[] = { { "Скобки расставлены неверно" }, { "Скобки расставлены верно" } };
	
	for (int i = 0; symb[i] != '\0'; i++) {
		if (symb[i] == '(' || symb[i] == '{' || symb[i] == '[') {
			push(symb[i], stack);
		}
		if (symb[i] == ')' || symb[i] == '}' || symb[i] == ']') {
			if (stack == NULL) {
				std::cout << tf[0] << std::endl;
				exit(EXIT_FAILURE);
			}
			else {
				if (symb[i] == ')' && pop(stack) == '(') {
					continue;
				}
				else if(symb[i] == '}' && pop(stack) == '{') {
					continue;
				}
				else if (symb[i] == ']' && pop(stack) == '[') {
					continue;
				}
				else
					std::cout << tf[0] << std::endl;
				exit(EXIT_FAILURE);
			}
		}
	}

	std::cout << tf[stack == NULL] << std::endl;
	
	return 0;
}

void push(char symb, MATH*& stack) {
	MATH* e = new MATH;
	e->a = symb;
	e->next = stack;
	stack = e;
}
char pop(MATH*& myStk)
{
	if (myStk == NULL)
	{
		return -1;         
	}
	else
	{
		MATH* e = myStk;
		char x = myStk->a;
		if (myStk)
			myStk = myStk->next;
		delete e;
		return x;
	}
}
