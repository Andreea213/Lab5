#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define CARTI_TOTAL 52

struct Coada {
    int date[MAX];
    int fata;
    int spate;
    int nr_elemente;
};

void initCoada(struct Coada* c) {
    c->fata = 0;
    c->spate = -1;
    c->nr_elemente = 0;
}

void adauga(struct Coada* c, int x) {
    if (c->nr_elemente < MAX) {
        c->spate = (c->spate + 1) % MAX;
        c->date[c->spate] = x;
        c->nr_elemente++;
    }
}

int scoate(struct Coada* c) {
    if (c->nr_elemente > 0) {
        int x = c->date[c->fata];
        c->fata = (c->fata + 1) % MAX;
        c->nr_elemente--;
        return x;
    }
    return -1;
}

void amesteca_pachet(int* pachet, int n) {
    for (int i = 0; i < n; i++) {
        int j = i + rand() % (n - i);
        int temp = pachet[i];
        pachet[i] = pachet[j];
        pachet[j] = temp;
    }
}

int main() {
    struct Coada j1, j2;
    int pachet[CARTI_TOTAL];
    int i, k = 0, runde = 0;
    int carte1, carte2;

    initCoada(&j1);
    initCoada(&j2);
    srand(time(NULL));

    for (int val = 2; val <= 14; val++) {
        for (i = 0; i < 4; i++) {
            pachet[k++] = val;
        }
    }

    amesteca_pachet(pachet, CARTI_TOTAL);

    for (i = 0; i < CARTI_TOTAL; i++) {
        if (i < CARTI_TOTAL / 2) {
            adauga(&j1, pachet[i]);
        } else {
            adauga(&j2, pachet[i]);
        }
    }

    while (j1.nr_elemente > 0 && j2.nr_elemente > 0) {
        runde++;
        carte1 = scoate(&j1);
        carte2 = scoate(&j2);

        if (carte1 > carte2) {
            adauga(&j1, carte1);
            adauga(&j1, carte2);
        } else if (carte2 > carte1) {
            adauga(&j2, carte2);
            adauga(&j2, carte1);
        }
    }

    if (j1.nr_elemente > 0) {
        printf("Castigator: Jucatorul 1\n");
    } else if (j2.nr_elemente > 0) {
        printf("Castigator: Jucatorul 2\n");
    } else {
        printf("Egalitate (ambii au ramas fara carti)\n");
    }

    printf("Numar de runde jucate: %d\n", runde);

    return 0;
}
