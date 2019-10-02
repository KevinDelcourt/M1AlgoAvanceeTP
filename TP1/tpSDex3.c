#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

int taille_max = 0;
int taille = 0;

//10000 add successifs -> temps moyen: 2.0049800ms sur 100 parcours --> 12752 swap
//buildheap du tab de 10000 -> temps moyen: 1.7354900ms sur 100 essais --> 7411 swap

//Temps pour les 40 plus grands de 100000 -> 5.0410000ms
void permut(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int left(i)
{
    return 2 * i;
}

int right(i)
{
    return 2 * i + 1;
}

int parent(i)
{
    return floor(i / 2);
}

void percolate_down(int *tableau, int n, int i)
{
    int m;
    if (left(i) < n && tableau[i] < tableau[left(i)])
    {
        m = left(i);
    }
    else
    {
        m = i;
    }

    if (right(i) < n && tableau[m] < tableau[right(i)])
        m = right(i);

    if (m != i)
    {
        permut(&tableau[i], &tableau[m]);
        percolate_down(tableau, n, m);
    }
}

void percolate_up(int *tableau, int i)
{
    int j = parent(i);
    while (i > 0 && tableau[j] < tableau[i])
    {
        permut(&tableau[i], &tableau[j]);
        i = j;
        j = parent(i);
    }
}

void buildHeap(int *tableau, int n)
{
    int i;
    for (i = floor(n / 2); i >= 0; i--)
    {
        percolate_down(tableau, n, i);
    }
}

void add(int *tableau, int i, int value)
{
    if (taille < taille_max)
    {
        taille++;
        tableau[i] = value;
        percolate_up(tableau, i);
    }
    else
    {
        printf("\n Tentative d'ajout sur un tableau plein! \n");
    }
}

int removeMax(int *tableau)
{
    int max = tableau[0];
    tableau[0] = tableau[taille - 1];
    taille--;
    percolate_down(tableau, taille, 0);
    return max;
}

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

    read_data(f_in, &data, &n, &k);
    taille_max = n;
    taille = taille_max;

    buildHeap(data, n);

    printf("Données (tas binaire) : \n");
    print_data(data, n);

    printf("Recherche des %d plus grands éléments du tableau de taille %d : \n", k, n);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", removeMax(data));
    }

    duree = clock() - duree;
    duree_ms += duree / (double)CLOCKS_PER_SEC * 1000;
    printf("\nfait en %.7fms\n", duree_ms);

    free(data);
    return 0;
}
