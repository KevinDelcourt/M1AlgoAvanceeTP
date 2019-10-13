#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "binaryTrees.h"

//Temps pour les 40 plus grands de 100000 -> 8.1550000ms // 393946 permutations

int *data;
int *dataCopy;
int n, k;

void doBubbleSort()
{
    bubbleSort(dataCopy, n, k);
    print_data(dataCopy, k);
}

void doBuildHeapRemove()
{
    struct BinaryTree btree = buildHeap(dataCopy, n);
    for (int i = 0; i < k; i++)
        printf("%d ", removeMax(&btree));
    printf("\n");
}

void doHeapSort()
{
    struct BinaryTree btree = buildHeap(dataCopy, n);
    heapSort(&btree);
    reverse_print_data(btree.data, k, n);
}

void doQuickSort()
{
    quickSort(dataCopy, 0, n - 1);
    print_data(dataCopy, k);
}

void monitoredLaunch(char *title, void (*doSort)(void))
{
    arrayCopy(data, &dataCopy, n);
    monitorLaunch(title);
    doSort();
    monitorStop();
}

int main(int argc, char **argv)
{
    read_data(argc, argv, &data, &n, &k);

    printf("Données : \n");
    print_data(data, n);

    printf("\nRecherche des %d plus grands éléments du tableau de taille %d : \n", k, n);

    monitoredLaunch("BubbleSort partiel", doBubbleSort);

    monitoredLaunch("BuildHeap / remove", doBuildHeapRemove);

    monitoredLaunch("HeapSort", doHeapSort);

    monitoredLaunch("QuickSort", doQuickSort);

    free(data);
    free(dataCopy);
    return 0;
}
