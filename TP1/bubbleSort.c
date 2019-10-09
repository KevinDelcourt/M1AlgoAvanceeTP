#include <stdio.h>
#include "utils.h"
//Temps pour les 40 plus grands de 100000 -> 8.1550000ms // 393946 permutations
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

int main(int argc, char **argv)
{
    start_clock();
    int *data;
    int n, k;

    /* read the data from the file given in arg or from stdin */
    read_data(argc, argv, &data, &n, &k);

    printf("Données : \n");
    print_data(data, n);

    printf("Recherche des %d plus grands éléments du tableau de taille %d : \n", k, n);
    bubbleSort(data, n, k);
    print_data(data, k);

    printf("\nfait en %.7fms\n", get_clock_time_in_ms());

#ifdef COMPTEUR_PERMUTATION
    extern int nb_permut;
    printf("\n%d permutations effectuées\n", nb_permut);
#endif

    free(data);
    return 0;
}
