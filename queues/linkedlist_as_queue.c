#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

void traversal(struct node *ptr) {
    while (ptr != NULL) {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val) {
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("Memory allocation failed. Queue is full.\n");
        return;
    }
    n->data = val;
    n->next = NULL;
    if (f == NULL) {
        f = r = n;
    } else {
        r->next = n;
        r = n;
    }
}

int dequeue() {
    int val = -1;
    if (f == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return val;
    }
    struct node *ptr = f;
    f = f->next;
    val = ptr->data;
    free(ptr);
    return val;
}

int main() {
    // Initial queue is empty
    traversal(f);

    enqueue(4);
    enqueue(5);
    enqueue(6);

    printf("Queue after enqueue operations:\n");
    traversal(f);

    printf("Dequeue element is %d\n", dequeue());

    printf("Queue after dequeue operation:\n");
    traversal(f);

    return 0;
}
