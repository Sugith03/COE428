#include <stdio.h>
#include <stdlib.h>

extern int pop();
extern void push(int);
extern int isEmpty();

static int heap[100];
static int size = 0;

void Bigint(int heap[], int size, int num); // declare Bigint function

int heapDelete() {
    if (size == 0) {
        fprintf(stderr, "There is nothing to delete");
        exit(1);
    }
    int maxval;
    maxval = heap[0];
    heap[0] = heap[size - 1];
    size--;
    Bigint(heap, size, 0);
    return maxval;
}

void addHeap(int thing2add) {
    heap[size] = thing2add;
    size++;
}

int heapSize() {
    return size;
}

void Bigint(int heap[], int size, int num) {
    int parent = num;
    int Leftchild = (2 * num) + 1;
    int Rightchild = (2 * num) + 2;

    if (Leftchild < size && heap[Leftchild] > heap[parent]) {
        parent = Leftchild;
    }

    if (Rightchild < size && heap[Rightchild] > heap[parent]) {
        parent = Rightchild;
    }

    if (parent != num) {
        int temp = heap[num];
        heap[num] = heap[parent];
        heap[parent] = temp;

        Bigint(heap, size, parent);
    }
}

void fullMaxHeapify() {
    for (int i = (size / 2) - 1; i >= 0; i--)
        Bigint(heap, size, i);
}

void heapSortPushStack() {
    for (int i = (size / 2) - 1; i >= 0; i--) {
        Bigint(heap, size, i);
    }
    for (int i = size - 1; i >= 0; i--) {
        push(heap[0]);
        printf("%d\n", heap[0]);

        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;

        Bigint(heap, i, 0);
    }
}

void printNode(int size, int num) {
    int parent = num;
    int left = 2 * num + 1;
    int right = 2 * num + 2;
    if (parent < size)
        printf("<node id=%d>", heap[parent]);

    if (left < size)
        printNode(size, left);

    if (right < size)
        printNode(size, right);

    if (parent < size)
        printf("</node>");
}

