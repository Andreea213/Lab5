#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

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

void adauga_coada(struct Coada* c, int x) {
    if (c->nr_elemente < MAX) {
        c->spate = (c->spate + 1) % MAX;
        c->date[c->spate] = x;
        c->nr_elemente++;
    }
}

int scoate_coada(struct Coada* c) {
    if (c->nr_elemente > 0) {
        int x = c->date[c->fata];
        c->fata = (c->fata + 1) % MAX;
        c->nr_elemente--;
        return x;
    }
    return -1;
}

struct Stiva {
    int date[MAX];
    int varf;
};

void initStiva(struct Stiva* s) {
    s->varf = -1;
}

void adauga_stiva(struct Stiva* s, int x) {
    if (s->varf < MAX - 1) {
        s->date[++(s->varf)] = x;
    }
}

int scoate_stiva(struct Stiva* s) {
    if (s->varf >= 0) {
        return s->date[(s->varf)--];
    }
    return -1;
}

int main() {
    struct Coada jucatori;
    struct Stiva ordine_iesire;
    int n, i, j, hot_potato, jucator_curent, eliminat;

    initCoada(&jucatori);
    initStiva(&ordine_iesire);
    srand(time(NULL));

    printf("Introduceti numarul de jucatori: ");
    if (scanf("%d", &n) != 1) return 1;

    for (i = 1; i <= n; i++) {
        adauga_coada(&jucatori, i);
    }

    while (jucatori.nr_elemente > 0) {
       hot_potato = (rand() % 10) + 1;
        
        for (j = 0; j < hot_potato - 1; j++) {
            jucator_curent = scoate_coada(&jucatori);
            adauga_coada(&jucatori, jucator_curent);
        }

        eliminat = scoate_coada(&jucatori);
        adauga_stiva(&ordine_iesire, eliminat);
    }

    printf("\nOrdinea descrescatoare (Castigator -> Primul eliminat):\n");
    while (ordine_iesire.varf >= 0) {
        printf("Jucator %d\n", scoate_stiva(&ordine_iesire));
    }

    return 0;
}
