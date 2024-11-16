#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;}
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data); }f (data < root->data) {
        root->left = insert(root->left, data); } else if (data > root->data) {
        root->right = insert(root->right, data); }
    return root;}
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;}
    if (key < root->data) {
        return search(root->left, key); }
    return search(root->right, key);}
struct Node* findMin(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;}
    return current;}
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root; }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp; }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);}
    return root;}
void inorderTraversal(struct Node* root) {
    if (root != NULL) { inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right); }}
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 20);
    insert(root, 30);
    insert(root, 90);
    inorderTraversal(root);
    printf("\nDelete 20:\n");
    root = deleteNode(root, 20);
    inorderTraversal(root);
    printf("\nDelete 50(ROOT NODE):\n");
    root = deleteNode(root, 50);
    inorderTraversal(root);
    return 0;
    }


