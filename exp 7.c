#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();
void clearList();

void main() {
    int choice = 0;
    while (choice != 9) {
        printf("\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n1.Insert in beginning\n2.Insert at last\n3.Insert at Random Position\n4.Delete from Beginning\n5.Delete from Last\n6.Delete from Random Position\n7.Search for an element\n8.Show\n9.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                beginsert();
                break;
            case 2:
                lastinsert();
                break;
            case 3:
                randominsert();
                break;
            case 4:
                begin_delete();
                break;
            case 5:
                last_delete();
                break;
            case 6:
                random_delete();
                break;
            case 7:
                search();
                break;
            case 8:
                display();
                break;
            case 9:
                clearList();
                exit(0);
                break;
            default:
                printf("Please enter a valid choice..\n");
        }
    }
}

void beginsert() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
    } else {
        printf("\nEnter the node data? ");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL) {
            head = ptr;
            ptr->next = head;
        } else {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            ptr->next = head;
            temp->next = ptr;
            head = ptr;
        }
        printf("\nNode inserted\n");
    }
}

void lastinsert() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
    } else {
        printf("\nEnter Data? ");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL) {
            head = ptr;
            ptr->next = head;
        } else {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = head;
        }
        printf("\nNode inserted\n");
    }
}

void randominsert() {
    struct node *ptr, *temp;
    int item, pos, count = 0;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
    } else {
        printf("\nEnter the node data? ");
        scanf("%d", &item);
        ptr->data = item;

        if (head == NULL) {
            head = ptr;
            ptr->next = head;
        } else {
            printf("Enter position (0 for beginning, -1 for end): ");
            scanf("%d", &pos);
            if (pos == 0) {
                beginsert();
            } else if (pos == -1) {
                lastinsert();
            } else {
                temp = head;
                while (temp->next != head && count < pos - 1) {
                    temp = temp->next;
                    count++;
                }
                ptr->next = temp->next;
                temp->next = ptr;
            }
        }
        printf("\nNode inserted\n");
    }
}

void begin_delete() {
    struct node *ptr;
    if (head == NULL) {
        printf("\nUNDERFLOW\n");
    } else if (head->next == head) {
        free(head);
        head = NULL;
        printf("\nNode deleted\n");
    } else {
        ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = head->next;
        free(head);
        head = ptr->next;
        printf("\nNode deleted\n");
    }
}

void last_delete() {
    struct node *ptr, *preptr;
    if (head == NULL) {
        printf("\nUNDERFLOW\n");
    } else if (head->next == head) {
        free(head);
        head = NULL;
        printf("\nNode deleted\n");
    } else {
        ptr = head;
        while (ptr->next != head) {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = head;
        free(ptr);
        printf("\nNode deleted\n");
    }
}

void random_delete() {
    struct node *ptr, *temp;
    int pos, count = 0;
    if (head == NULL) {
        printf("\nUNDERFLOW\n");
    } else {
        printf("Enter position of node to delete (0 for beginning, -1 for end, or index): ");
        scanf("%d", &pos);

        if (pos == 0) {
            begin_delete();
        } else if (pos == -1) {
            last_delete();
        } else {
            ptr = head;
            while (ptr->next != head && count < pos - 1) {
                ptr = ptr->next;
                count++;
            }
            if (count == pos - 1 && ptr->next != head) {
                struct node *toDelete = ptr->next;
                ptr->next = toDelete->next;
                free(toDelete);
                printf("\nNode at position %d deleted\n", pos);
            } else {
                printf("Position out of bounds\n");
            }
        }
    }
}

void search() {
    struct node *ptr;
    int item, i = 0, flag = 1;
    ptr = head;
    if (ptr == NULL) {
        printf("\nEmpty List\n");
    } else {
        printf("\nEnter item which you want to search?\n");
        scanf("%d", &item);
        if (head->data == item) {
            printf("Item found at location %d\n", i + 1);
            flag = 0;
        } else {
            while (ptr->next != head) {
                if (ptr->data == item) {
                    printf("Item found at location %d\n", i + 1);
                    flag = 0;
                    break;
                } else {
                    flag = 1;
                }
                i++;
                ptr = ptr->next;
            }
        }
        if (flag != 0) {
            printf("Item not found\n");
        }
    }
}

void display() {
    struct node *ptr;
    ptr = head;
    if (head == NULL) {
        printf("\nNothing to print\n");
    } else {
        printf("\nPrinting values ...\n");
        do {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
    }
}

void clearList() {
    while (head != NULL) {
        begin_delete();
    }
    printf("\nAll nodes deleted\n");
}
