#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef COMPTEUR_PERMUTATION
int nb_permut = 0;
#endif

clock_t horloge;

void permut(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
#ifdef COMPTEUR_PERMUTATION
    nb_permut++;
#endif
}

void read_data(int argc, char **argv, int **dataout, int *n, int *k)
{
    FILE *f_in;
    int *data;

    if (argc > 1)
        f_in = fopen(argv[1], "r");
    else
        f_in = stdin;

    fscanf(f_in, "%d", n);
    fscanf(f_in, "%d", k);
    *dataout = (int *)malloc((*n) * sizeof(int));
    data = *dataout;

    for (int i = 0; i < *n; ++i, ++data)
        fscanf(f_in, "%d", data);
}

void print_data(int *tableau, int taille)
{
    for (int i = 0; i < taille; ++i)
        printf("%d ", tableau[i]);
    printf("\n");
}

void start_clock()
{
    horloge = clock();
}

double get_clock_time_in_ms()
{
    return (clock() - horloge) / (double)CLOCKS_PER_SEC * 1000;
}