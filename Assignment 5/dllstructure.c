#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* previous;
};

struct Node* malloc_Node() {
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	return node;
}

struct Node *create_dll_from_array(int array[], int size) {
	struct Node *head = NULL;
	struct Node *tail = NULL;

	struct Node *temp = NULL;

	for (int i = 0; i < size; i++) {
		tail = malloc_Node();
		tail->data = array[i];
		tail->next = NULL;
		tail->previous = NULL;
		if (temp == NULL) {
			temp = tail;
			head = temp;
		}
		temp->next = tail;
		tail->previous = temp;
		temp = tail;
	}
	return head;
}

void print_dll(struct Node *head) {
	struct Node *temp = NULL;
	temp = head;
	printf("\nPrinting DoublyLinkedList...\n");
	while (temp->next != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d\n", temp->data);
}

void insert_after(struct Node* head, int valueToInsertAfter, int valueToBeInserted) {
	int count = 0;

	struct Node *tail = NULL;
	struct Node *list = NULL;
	struct Node *temp = NULL;

	temp = head;

	while (temp->next != NULL) {
		if (valueToInsertAfter == temp->data) {
			list = malloc_Node();
			
			list->data = valueToBeInserted;
			tail = temp->next;
			temp->next = list;
			
			list->previous = temp;
			list->next = tail;
			tail->previous = list;
			
			count = 1;
			break;
		}
		temp = temp->next;
	}
	if (count == 0) {
		list = malloc_Node();
		list->data = valueToBeInserted;
		
		temp->next = list;
		list->previous = temp;
		list->next = NULL;
	}
}

void delete_element(struct Node* head, int valueToBeDeleted) {
	while (head->next != NULL) {
		if (head->data == valueToBeDeleted) {
			if (head->previous == NULL) {
				head->next->previous = NULL;
				*head = *head->next;
			}

			else if (head->next == NULL) {
				head->previous->next = NULL;
			}

			else {
				head->previous->next = head->next;
				head->next->previous = head->previous;
			}

			break;
		}
		head = head->next;
	}
}

void swap(struct Node *a, struct Node *b) {
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void sort_dll(struct Node* head) {
	int n, i;
	struct Node *p1;
	struct Node *p2 = NULL;

	if (head == NULL)
		return;
	do {
		n = 0;
		p1 = head;
		while (p1->next != p2) {
			if (p1->data > p1->next->data) {
				swap(p1, p1->next);
				n = 1;
			}
			p1 = p1->next;
		}
		p2 = p1;
	} while (n);
}

void free_list(struct Node* head) {
	if (head == NULL) {
		return;
	}
	else {
		free_list(head->next);
		free(head);
	}
}

int main(void) {
	int array[5] = { 11, 2, 7, 22, 4 };
	struct Node* head;

	head = create_dll_from_array(array, 5);

	print_dll(head);

	insert_after(head, 7, 13);
	insert_after(head, 21, 29);
	print_dll(head);

	delete_element(head, 22);
	print_dll(head);
	delete_element(head, 11);
	print_dll(head);

	sort_dll(head);
	print_dll(head);

	return 0;
}
