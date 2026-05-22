#include "calculator.h"
#include "ArrayStack.h"

int precedence(char op) {
	if (op == '*' || op == '/') {
		return 2;
	}
	else if (op == '+' || op == '-') {
		return 1;
	}
	else if (op == '(' || op == ')') {
		return 0;
	}
	return -1;
}
int infixToPostfix(char* infix, char* postfix) {
	int j = 0;
	ArrayStack* opStack = createArrayStack(100, CHARACTER);

	for (int i = 0; infix[i] != '\0'; i++) {
		if (infix[i] >= '0' && infix[i] <= '9') {
			postfix[j++] = infix[i];
			postfix[j] = '\0';
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
			while (!emptyArrayStack(opStack)) {
				stackElement prevOp = peekArrayStack(opStack);
				if (precedence(infix[i]) <= precedence(prevOp.operator)) {
					postfix[j++] = popArrayStack(opStack).operator;
					postfix[j] = '\0';
				}
				else {
					break;
				}
			}
			stackElement item;
			item.operator = infix[i];
			pushArrayStack(opStack, item);
		}
		else if (infix[i] == '(') {
			stackElement item;
			item.operator = infix[i];
			pushArrayStack(opStack, item);
		}
		else if (infix[i] == ')') {
			while (!emptyArrayStack(opStack)) {
				stackElement prevOp = popArrayStack(opStack);
				if (prevOp.operator == '(') {
					break;
				}
				postfix[j++] = prevOp.operator;
				postfix[j] = '\0';
			}
		}

		printf("- Postfix: %-15s | ", postfix);
		printArrayStack(opStack);
	}

	while (!emptyArrayStack(opStack)) {
		postfix[j++] = popArrayStack(opStack).operator;
		postfix[j] = '\0';
		printf("- Postfix: %-15s | ", postfix);
		printArrayStack(opStack);
	}
	postfix[j] = '\0';
}

int evalPostfix(char* postfix) {
	ArrayStack* valueStack = createArrayStack(100, INTEGER);
	int i = 0;

	while (postfix[i] != '\0') {
		printf("- Current: %c | ", postfix[i]);

		if (postfix[i] >= '0' && postfix[i] <= '9') {
			stackElement item;
			item.value = postfix[i] - '0';
			pushArrayStack(valueStack, item);
		}
		else {
			int i1 = popArrayStack(valueStack).value;
			int i2 = popArrayStack(valueStack).value;
			stackElement result;

			if (postfix[i] == '*') {
				result.value = i2 * i1;
			}
			else if (postfix[i] == '/') {
				result.value = i2 / i1;
			}
			else if (postfix[i] == '+') {
				result.value = i2 + i1;
			}
			else if (postfix[i] == '-') {
				result.value = i2 - i1;
			}
			pushArrayStack(valueStack, result);
		}

		printArrayStack(valueStack);
		i++;
	}

	return popArrayStack(valueStack).value;
}