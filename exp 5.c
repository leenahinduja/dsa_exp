#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;}
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;}
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;}
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next; }
    temp->next = newNode;}
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;}
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next; }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);}
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;}
    printf("NULL\n");}
int searchList(Node* head, int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) return 1; // Found
        temp = temp->next;  }
    return 0;}
int main() {
    Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    printf("Linked List: ");
    printList(head);
    printf("Searching for 30: %s\n", searchList(head, 30) ? "Found" : "Not Found");
    deleteNode(&head, 20);
    printf("Linked List after deleting 20: ");
    printList(head);
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);}
    return 0;
}
