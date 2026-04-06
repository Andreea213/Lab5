#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stiva {
    int date[MAX];
    int top;
};

void initStiva(struct Stiva* s) {
    s->top = -1;
}

int isEmpty(struct Stiva* s) {
    return s->top == -1;
}

void push(struct Stiva* s, int x) {
    if (s->top < MAX - 1) {
        s->date[++(s->top)] = x;
    }
}

int pop(struct Stiva* s) {
    if (!isEmpty(s)) {
        return s->date[(s->top)--];
    }
    return -1;
}

struct Coada {
    struct Stiva s1;
    struct Stiva s2;
};

void initCoada(struct Coada* q) {
    initStiva(&(q->s1));
    initStiva(&(q->s2));
}

void enqueue(struct Coada* q, int x) {
    push(&(q->s1), x);
}

int dequeue(struct Coada* q) {
    if (isEmpty(&(q->s1)) && isEmpty(&(q->s2))) {
        return -1;
    }

    if (isEmpty(&(q->s2))) {
        while (!isEmpty(&(q->s1))) {
            push(&(q->s2), pop(&(q->s1)));
        }
    }

    return pop(&(q->s2));
}

int peek(struct Coada* q) {
    if (isEmpty(&(q->s1)) && isEmpty(&(q->s2))) {
        return -1;
    }

    if (isEmpty(&(q->s2))) {
        while (!isEmpty(&(q->s1))) {
            push(&(q->s2), pop(&(q->s1)));
        }
    }

    return q->s2.date[q->s2.top];
}

int main() {
    struct Coada q;
    initCoada(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Element scos: %d\n", dequeue(&q));
    printf("Primul element: %d\n", peek(&q));
    printf("Element scos: %d\n", dequeue(&q));

    enqueue(&q, 40);
    printf("Element scos: %d\n", dequeue(&q));
    printf("Element scos: %d\n", dequeue(&q));

    return 0;
}
