#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enq(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Heap Overflow! Cannot allocate memory.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void deq() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Dequed value : %d\n", temp->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

void frontelement() {
    if (front == NULL) {
        printf("No front element in Queue\n");
        return;
    }
    printf("Front element : %d\n", front->data);
}

void empty() {
    if (front == NULL) {
        printf("Queue empty\n");
    } else {
        printf("Queue not empty\n");
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void queuesize() {
    int count = 0;
    struct Node* temp = front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Queue size : %d\n", count);
}

int main() {
    int choice, value;

    printf("\n 1 - Enque\n 2 - Deque\n 3 - Front element\n 4 - Empty\n 5 - Exit\n 6 - Display\n 7 - Queue size\n");

    while (1) {
        printf("\nEnter choice : ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter data : ");
                scanf("%d", &value);
                enq(value);
                break;
            case 2:
                deq();
                break;
            case 3:
                frontelement();
                break;
            case 4:
                empty();
                break;
            case 5:
                exit(0);
            case 6:
                display();
                break;
            case 7:
                queuesize();
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

 1 - Enque
 2 - Deque
 3 - Front element
 4 - Empty
 5 - Exit
 6 - Display
 7 - Queue size

Enter choice : 1
Enter data : 14

Enter choice : 1
Enter data : 85

Enter choice : 1
Enter data : 38

Enter choice : 3
Front element : 14

Enter choice : 6
14 85 38

Enter choice : 7
Queue size : 3

Enter choice : 2
Dequed value : 14

Enter choice : 6
85 38

Enter choice : 7
Queue size : 2

Enter choice : 4
Queue not empty

Enter choice : 5

============================================================
RESULT
============================================================

Thus the program for linked list implementation of queue ADT
has been executed successfully.

============================================================
*/
