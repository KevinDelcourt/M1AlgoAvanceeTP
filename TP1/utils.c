#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int nb_permut = 0;

clock_t horloge;

void worstCaseGenerator(int *output, int size)
{
    for (int i = 0; i < size; i++)
    {
        output[i] = i;
    }
}

void permut(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    nb_permut++;
}

void read_data(int argc, char **argv, int **dataout, int *n, int *k)
{
    FILE *f_in;
    int *data;
    int val;

    if (argc > 1)
        f_in = fopen(argv[1], "r");
    else
        f_in = stdin;

    fscanf(f_in, "%d", n);
    fscanf(f_in, "%d", k);
    *dataout = (int *)malloc((*n) * sizeof(int));
    data = *dataout;
    //worstCaseGenerator(data, *n);
    for (int i = 0; i < *n; ++i, ++data)
        fscanf(f_in, "%d", data);
}

void print_data(int *tableau, int taille)
{
    int n = taille;
    if (taille > 100)
        n = 100;

    for (int i = 0; i < n; ++i)
        printf("%d ", tableau[i]);
    printf("\n");
}

void reverse_print_data(int *tableau, int taille, int taille_max)
{
    int n = taille;
    if (taille > 100)
        n = 100;

    for (int i = taille_max - 1; i > taille_max - n - 1; i--)
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

void monitorLaunch(char *title)
{
    printf("\nLancement de: \033[0;35m%s\033[0m\n", title);
    nb_permut = 0;
    start_clock();
}

struct Activity monitorStop()
{

    struct Activity activity = {nb_permut, get_clock_time_in_ms()};
    printf("\nTemps d'exécution: \033[0;36m%.7fms\033[0m\n", activity.timeSpent);
    printf("Permutations: \033[0;36m%d\033[0m\n", activity.nbPermut);
    return activity;
}

void bubbleSort(int *tableau, int n, int k)
{
    int i, j;
    for (i = 0; i < k; i++)
    {
        for (j = n - 2; j >= i; j--)
        {
            if (tableau[j] < tableau[j + 1])
            {
                permut(&tableau[j + 1], &tableau[j]);
            }
        }
    }
}

void quickSort(int *tableau, int first, int last)
{
    int i, j, pivot;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (tableau[i] >= tableau[pivot] && i < last)
                i++;
            while (tableau[j] < tableau[pivot])
                j--;
            if (i < j)
                permut(&tableau[i], &tableau[j]);
        }
        permut(&tableau[j], &tableau[pivot]);
        quickSort(tableau, first, j - 1);
        quickSort(tableau, j + 1, last);
    }
}

void arrayCopy(int *source, int **destination, int size)
{
    *destination = (int *)malloc((size) * sizeof(int));
    memcpy(*destination, source, sizeof(int) * size);
}
