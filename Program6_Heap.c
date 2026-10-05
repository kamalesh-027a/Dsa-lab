#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap[index] > heap[parent]) {
        swap(&heap[index], &heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapifyDown(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < size && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapifyDown(largest);
    }
}

void insert(int value) {
    if (size >= MAX) {
        printf("Heap Overflow! Cannot insert more elements.\n");
        return;
    }
    heap[size] = value;
    size++;
    heapifyUp(size - 1);
}

void deleteRoot() {
    if (size <= 0) {
        printf("Heap Underflow! Heap is empty.\n");
        return;
    }
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

void display() {
    int i;
    if (size == 0) {
        printf("Heap is empty.\n");
        return;
    }
    for (i = 0; i < size; i++) {
        printf("%d", heap[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                deleteRoot();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

/*
============================================================
OUTPUT
============================================================

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 50

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 30

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 20

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 15

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 3
50 30 20 15

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 2

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 3
30 15 20

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 4

============================================================
RESULT
============================================================

Thus the c program to implement heaps has been successfully implemented.

============================================================
*/
