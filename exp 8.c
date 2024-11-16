#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};
struct Node* createNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = newNode->prev = NULL;
	return newNode;
}
void insertAtBeginning(struct Node** head, int data) {
	struct Node* newNode = createNode(data);

	if (*head == NULL) {
    	*head = newNode;
    	(*head)->next = *head;
    	(*head)->prev = *head;
	} else {
    	struct Node* tail = (*head)->prev;
    	newNode->next = *head;
    	newNode->prev = tail;
    	tail->next = newNode;
    	(*head)->prev = newNode;
    	*head = newNode;
	}
}
void insertAtEnd(struct Node** head, int data) {
	struct Node* newNode = createNode(data);
	if (*head == NULL) {
    	*head = newNode;
    	(*head)->next = *head;
    	(*head)->prev = *head;
	} else {
    	struct Node* tail = (*head)->prev;
    	tail->next = newNode;
    	newNode->prev = tail;
    	newNode->next = *head;
    	(*head)->prev = newNode;
	}
}
void displayForward(struct Node* head) {
	if (head == NULL) {
    	printf("List is empty.\n");
    	return;
	}
	struct Node* temp = head;
	do {
    	printf("%d ", temp->data);
    	temp = temp->next;
	} while (temp != head);
	printf("\n");
}
void displayBackward(struct Node* head) {
	if (head == NULL) {
    	printf("List is empty.\n");
    	return;
	}
	struct Node* tail = head->prev;
	struct Node* temp = tail;

	do {
    	printf("%d ", temp->data);
    	temp = temp->prev;
	} while (temp != tail);
	printf("\n");
}
void deleteFromBeginning(struct Node** head) {
	if (*head == NULL) {
    	printf("List is empty.\n");
    	return;
	}
	struct Node* temp = *head;
    	if ((*head)->next == *head) {
    	free(*head);
    	*head = NULL;
	} else {
    	struct Node* tail = (*head)->prev;
    	*head = (*head)->next;
    	(*head)->prev = tail;
    	tail->next = *head;
    	free(temp);
	}
}
void deleteFromEnd(struct Node** head) {
	if (*head == NULL) {
    	printf("List is empty.\n");
    	return;
	}
	struct Node* tail = (*head)->prev;
	if (tail == *head) {
    	free(*head);
    	*head = NULL;
	} else {
    	struct Node* secondLast = tail->prev;
    	secondLast->next = *head;
    	(*head)->prev = secondLast;
    	free(tail);
	}
}
int main() {
	struct Node* head = NULL;
	insertAtEnd(&head, 1);
	insertAtEnd(&head, 2);
	insertAtEnd(&head, 3);
	printf("Circular Doubly Linked List (Forward): ");
	displayForward(head);
	printf("Circular Doubly Linked List (Backward): ");
	displayBackward(head);
	insertAtBeginning(&head, 4);
	printf("After inserting at the beginning (Forward): ");
	displayForward(head);
	deleteFromEnd(&head);
	printf("After deleting from the end (Forward): ");
	displayForward(head);
	deleteFromBeginning(&head);
	printf("After deleting from the beginning (Forward): ");
	displayForward(head);
	return 0;
}
