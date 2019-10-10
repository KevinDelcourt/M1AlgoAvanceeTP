#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include "utils.h"
#include "binaryTrees.h"

int main(int argc, char **argv)
{

    int *data;
    int n, k;
    read_data(argc, argv, &data, &n, &k);
    struct BinaryTree btree = buildHeap(data, n);

    heapSort(&btree);

    print_data(data, n);

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
