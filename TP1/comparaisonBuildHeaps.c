#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include "utils.h"
#include "binaryTrees.h"

int main(int argc, char **argv)
{
#ifdef COMPTEUR_PERMUTATION
    extern int nb_permut;
#endif
    start_clock();
    int *data;
    int n, k;
    read_data(argc, argv, &data, &n, &k);
    int dataAdd[n];
    struct BinaryTree btree1 = buildHeapSuccessiveAdd(data, dataAdd, n);
    double t1 = get_clock_time_in_ms();
    start_clock();
#ifdef COMPTEUR_PERMUTATION
    int nb1 = nb_permut;
#endif

    struct BinaryTree btree2 = buildHeap(data, n);
    double t2 = get_clock_time_in_ms();

    printf("\n\tTas binaire fait avec add\n");
    printBinaryTree(btree1);

    printf("\n\tTas binaire fait avec buildHeap \n");
    printBinaryTree(btree2);

    printf("\n\033[0;33m%.7fms\033[0m avec add\n", t1);
#ifdef COMPTEUR_PERMUTATION
    printf("\033[0;33m%d\033[0m permutations effectuées\n", nb1);
#endif
    printf("\n\033[0;34m%.7fms\033[0m avec BuildHeap classique\n", t2);
#ifdef COMPTEUR_PERMUTATION
    printf("\033[0;34m%d\033[0m permutations effectuées\n", nb_permut - nb1);
#endif

    /*printf("Recherche des %d plus grands éléments du tableau de taille %d : \n", k, n);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", removeMax(&btree));
    }*/

    free(data);
    return 0;
}

/*
Ex affichage pour tab de taille 10000
2.3360000ms avec add

    12697 permutations effectuées

    0.2610000ms avec BuildHeap classique

    7424 permutations effectuées
    
    */
