#define _CRT_SECURE_NO_WARNINGS
#include "Linkedstack.h"
#include <string.h>

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
	Node* n = (Node*)malloc(sizeof(Node));
	n->data =(char*)malloc(strlen(item) + 1);
	strcpy(n->data, item);
	n->next = s->head;
	s->head = n;
	s->size++;
	return 1;
}

void printLinkedStack(LinkedStack* s) {
	printf("Stack:\n");
	printf("Size: %d\n", s->size);
	Node* temp = s->head;
	while (temp != NULL) {
		printf("%s\n", temp->data);
		temp = temp->next;
	}
}

void destroyLinkedStack(LinkedStack* s) {
	while (!emptyLinkedStack(s)) {
		char* data = popLinkedStack(s);
		free(data);
	}
	free(s);
}

stackElement popLinkedStack(LinkedStack* s) {

	if (emptyLinkedStack(s)) {
		return NULL;
	}
	Node* n = s->head;
	stackElement data = n->data;
	s->head = n->next;
	free(n);
	s->size--;
	return data;
}

stackElement peekLinkedStack(LinkedStack* s) {

	if (emptyLinkedStack(s)) {
		return NULL;
	}

	return s->head->data;
}

