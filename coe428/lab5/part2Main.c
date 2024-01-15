#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

extern int pop();
extern void push(int);
extern int isEmpty();
extern int heapDelete();
extern void addHeap(int);
extern int heapSize();
extern void Bigint(int[], int, int);
extern void fullMaxHeapify();
extern void heapSortPushStack();
extern void printNode(int, int);

int main(int argc, char* argv[]) {
    int val;
    printf("Enter your inputs.\n");

    if (scanf("%d", &val) != 1) {
        fprintf(stderr, "Please enter a number");
        exit(1);
    }

    while (val != EOF && val != -1) {
        addHeap(val);

        if (scanf("%d", &val) != 1) {
            fprintf(stderr, "Please enter a number");
            exit(1);
        }
    }

    fullMaxHeapify();
    printNode(heapSize(), 0);
    printf("\n");

    printf("Descending: \n");
    heapSortPushStack();
    printf("Popped:\n");
    for (int i = 0; i < heapSize(); i++) {
        printf("%d\n", pop());
    }

    exit(0);
}
