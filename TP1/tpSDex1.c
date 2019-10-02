#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//Temps pour les 40 plus grands de 100000 -> 263.1550000ms

void read_data(FILE *datain, int **dataout, int *n, int *k)
{
    int *data;

    fscanf(datain, "%d", n);
    fscanf(datain, "%d", k);
    *dataout = (int *)malloc((*n) * sizeof(int));
    data = *dataout;

    for (int i = 0; i < *n; ++i, ++data)
        fscanf(datain, "%d", data);
}

void print_data(int *tableau, int taille)
{
    for (int i = 0; i < taille; ++i)
        printf("%d ", tableau[i]);
    printf("\n");
}

void permut(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int *tableau, int n, int k)
{
    int i, j;
    for (i = n - 1; i >= k; i--)
    {
        for (j = i - 1; j >= 0; j--)
        {
            if (tableau[j] < tableau[j + 1])
            {
                permut(&tableau[j + 1], &tableau[j]);
            }
        }
    }
}

int main(int argc, char **argv)
{
    clock_t duree = clock();
    double duree_ms;
    int *data;
    int n, k;
    FILE *f_in;

    if (argc > 1)
        f_in = fopen(argv[1], "r");
    else
        f_in = stdin;

    /* read the data from the file given in arg or from stdin */
    read_data(f_in, &data, &n, &k);

    printf("Données : \n");
    print_data(data, n);

    printf("Recherche des %d plus grands éléments du tableau de taille %d : \n", k, n);
    bubbleSort(data, n, k);
    print_data(data, k);

    duree = clock() - duree;
    duree_ms += duree / (double)CLOCKS_PER_SEC * 1000;
    printf("\nfait en %.7fms\n", duree_ms);

    free(data);
    return 0;
}
