#include <stdio.h>
#include "utils.h"
//Temps pour les 40 plus grands de 100000 -> 8.1550000ms // 393946 permutations

int main(int argc, char **argv)
{
    int *data;
    int n, k;

    /* read the data from the file given in arg or from stdin */
    read_data(argc, argv, &data, &n, &k);

    printf("Données : \n");
    print_data(data, n);

    printf("Recherche des %d plus grands éléments du tableau de taille %d : \n", k, n);

    monitorLaunch("BubbleSort partiel");
    bubbleSort(data, n, k);
    print_data(data, k);
    monitorStop();

    free(data);
    return 0;
}
