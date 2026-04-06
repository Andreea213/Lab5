#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

struct Stiva {
    int date[MAX];
    int top;
};

void initStiva(struct Stiva* s) {
    s->top = -1;
}

bool isEmptyStiva(struct Stiva* s) {
    return s->top == -1;
}

bool isFullStiva(struct Stiva* s) {
    return s->top == MAX - 1;
}

void push(struct Stiva* s, int x) {
    if (!isFullStiva(s)) {
        s->date[++(s->top)] = x;
    }
}

int pop(struct Stiva* s) {
    if (!isEmptyStiva(s)) {
        return s->date[(s->top)--];
    }
    return -1;
}

int peekStiva(struct Stiva* s) {
    if (!isEmptyStiva(s)) {
        return s->date[s->top];
    }
    return -1;
}

struct Coada {
    int date[MAX];
    int front;
    int rear;
    int count;
};

void initCoada(struct Coada* q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

bool isEmptyCoada(struct Coada* q) {
    return q->count == 0;
}

bool isFullCoada(struct Coada* q) {
    return q->count == MAX;
}

void enqueue(struct Coada* q, int x) {
    if (!isFullCoada(q)) {
        q->rear = (q->rear + 1) % MAX;
        q->date[q->rear] = x;
        q->count++;
    }
}

int dequeue(struct Coada* q) {
    if (!isEmptyCoada(q)) {
        int x = q->date[q->front];
        q->front = (q->front + 1) % MAX;
        q->count--;
        return x;
    }
    return -1;
}

int peekCoada(struct Coada* q) {
    if (!isEmptyCoada(q)) {
        return q->date[q->front];
    }
    return -1;
}

int main() {
    struct Stiva s;
    initStiva(&s);
    push(&s, 10);
    push(&s, 20);
    printf("%d\n", pop(&s));

    struct Coada q;
    initCoada(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    printf("%d\n", dequeue(&q));

    return 0;
}
