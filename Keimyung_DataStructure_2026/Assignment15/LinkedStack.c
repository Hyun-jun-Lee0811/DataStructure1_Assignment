#include "Linkedstack.h"

LinkedStack* createLinkedStack() {
	LinkedStack* re = (LinkedStack*)malloc(sizeof(LinkedStack));
	re->head = NULL;
	re->size = 0;

	return re;
}

int emptyLinkedStack(LinkedStack* s) {
	return s->size == 0;
}

int fullLinkedStack(LinkedStack* s) {
	return 0;
}

int pushLinkedStack(LinkedStack* s, stackElement item) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = s->head;
	s->head = temp;
	s->size++;
	return 1;
}

void printLinkedStack(LinkedStack* s) {
	printf("Stack:\n");
	printf("Size: %d\n", s->size);
	Node* temp = s->head;
	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

void destroyLinkedStack(LinkedStack* s) {

	while (!emptyLinkedStack(s)) {
		popLinkedStack(s);
	}

	free(s);
}

stackElement popLinkedStack(LinkedStack* s) {

	if (emptyLinkedStack(s)) {
		return NULL;
	}

	Node* temp = s->head;

	stackElement data = temp->data;

	s->head = temp->next;

	free(temp);

	s->size--;

	return data;
}

stackElement peekLinkedStack(LinkedStack* s) {

	if (emptyLinkedStack(s)) {
		return NULL;
	}

	return s->head->data;
}

