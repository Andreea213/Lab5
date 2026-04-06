#include <stdio.h>
#include <stdlib.h>

struct DouaStive {
    int* vector;
    int top1;
    int top2;
    int capacitate;
};

struct DouaStive* create(int n) {
    struct DouaStive* ds = (struct DouaStive*)malloc(sizeof(struct DouaStive));
    ds->capacitate = n;
    ds->vector = (int*)malloc(n * sizeof(int));
    ds->top1 = -1;
    ds->top2 = n;
    return ds;
}

void push1(struct DouaStive* ds, int x) {
    if (ds->top1 < ds->top2 - 1) {
        ds->vector[++(ds->top1)] = x;
    }
}

void push2(struct DouaStive* ds, int x) {
    if (ds->top1 < ds->top2 - 1) {
        ds->vector[--(ds->top2)] = x;
    }
}

int pop1(struct DouaStive* ds) {
    if (ds->top1 >= 0) {
        return ds->vector[(ds->top1)--];
    }
    return -1;
}

int pop2(struct DouaStive* ds) {
    if (ds->top2 < ds->capacitate) {
        return ds->vector[(ds->top2)++];
    }
    return -1;
}

int main() {
    struct DouaStive* ds = create(10);

    push1(ds, 5);
    push1(ds, 10);
    push2(ds, 100);
    push2(ds, 200);

    printf("%d\n", pop1(ds));
    printf("%d\n", pop2(ds));

    free(ds->vector);
    free(ds);
    return 0;
}
