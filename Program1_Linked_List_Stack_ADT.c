#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Heap Overflow! Cannot allocate memory.\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped value : %d\n", temp->data);
    top = top->next;
    free(temp);
}

void top_element() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element : %d\n", top->data);
}

void is_empty() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void stack_count() {
    int count = 0;
    struct Node* temp = top;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("No. of elements in stack : %d\n", count);
}

void destroy() {
    struct Node* temp = top;
    struct Node* nextNode = NULL;
    while (temp != NULL) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    top = NULL;
    printf("All stack elements destroyed\n");
}

int main() {
    int choice, value;

    printf("\n 1 - Push\n 2 - Pop\n 3 - Top\n 4 - Empty\n 5 - Exit\n 6 - Dipslay\n 7 - Stack Count\n 8 - Destroy stack\n");

    while (1) {
        printf("\nEnter choice : ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter data : ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                top_element();
                break;
            case 4:
                is_empty();
                break;
            case 5:
                exit(0);
            case 6:
                display();
                break;
            case 7:
                stack_count();
                break;
            case 8:
                destroy();
                break;
            default:
                printf("Wrong choice\n");
                break;
        }
    }

    return 0;
}

/*
============================================================
OUTPUT
============================================================

 1 - Push
 2 - Pop
 3 - Top
 4 - Empty
 5 - Exit
 6 - Dipslay
 7 - Stack Count
 8 - Destroy stack

Enter choice : 1
Enter data : 56

Enter choice : 1
Enter data : 80

Enter choice : 2
Popped value : 80

Enter choice : 3
Top element : 56

Enter choice : 1
Enter data : 78

Enter choice : 1
Enter data : 90

Enter choice : 6
90 78 56

Enter choice : 7
No. of elements in stack : 3

Enter choice : 8
All stack elements destroyed

Enter choice : 4
Stack is empty

Enter choice : 5

============================================================
RESULT
============================================================

Thus the Linked list Implementation of Stack ADTs was executed successfully.

============================================================
*/
