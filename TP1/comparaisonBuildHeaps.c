#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include "utils.h"
#include "binaryTrees.h"

int main(int argc, char **argv)
{
    extern int nb_permut;
    start_clock();
    int *data;
    int n, k;
    read_data(argc, argv, &data, &n, &k);
    int dataAdd[n];
    struct BinaryTree btree1 = buildHeapSuccessiveAdd(data, dataAdd, n);
    double t1 = get_clock_time_in_ms();
    start_clock();
    int nb1 = nb_permut;

    struct BinaryTree btree2 = buildHeap(data, n);
    double t2 = get_clock_time_in_ms();

    printf("\n\tTas binaire fait avec add\n");
    printBinaryTree(btree1);

    printf("\n\tTas binaire fait avec buildHeap \n");
    printBinaryTree(btree2);

    printf("\n\033[0;33m%.7fms\033[0m avec add\n", t1);
    printf("\033[0;33m%d\033[0m permutations effectuées\n", nb1);
    printf("\n\033[0;34m%.7fms\033[0m avec BuildHeap classique\n", t2);
    printf("\033[0;34m%d\033[0m permutations effectuées\n", nb_permut - nb1);

    free(data);
    return 0;
}
