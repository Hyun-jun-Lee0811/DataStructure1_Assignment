#include <stdio.h>
#include "calculator.h"

int main() {
	char sample[] = "3+4*(5+6)*7";
	char postfix[100];

	printf("Transform:\n");
	infixToPostfix(sample, postfix);
	printf("\n- Result: %s\n\n", postfix);

	printf("Eval:\n- Postfix: %s\n", postfix);
	int result = evalPostfix(postfix);
	printf("\n- Result: %d\n", result);

	return 0;
}