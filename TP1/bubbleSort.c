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

struct Activity monitoredLaunch(char *title, void (*doSort)(void))
{
    arrayCopy(data, &dataCopy, n);
    monitorLaunch(title);
    doSort();
    return monitorStop();
}

int main(int argc, char **argv)
{
    FILE *f_out;

    read_data(argc, argv, &data, &n, &k);
    printf("Données : \n");
    print_data(data, n);

    printf("\nRecherche des %d plus grands éléments du tableau de taille %d : \n", k, n);

    /*f_out = fopen("out.csv", "w");
    fprintf(f_out, "k,BubbleSort partiel,BuildHeap / Remove,HeapSort\n");
    struct Activity activity;
    for (k = 1; k <= n; k++)
    {
        activity = monitoredLaunch("BubbleSort partiel", doBubbleSort);
        fprintf(f_out, "%d,%.7f,", k, activity.timeSpent);
        activity = monitoredLaunch("BuildHeap / remove", doBuildHeapRemove);
        fprintf(f_out, "%.7f,", activity.timeSpent);
        activity = monitoredLaunch("HeapSort", doHeapSort);
        fprintf(f_out, "%.7f\n", activity.timeSpent);
    }*/
    monitoredLaunch("BubbleSort partiel", doBubbleSort);
    monitoredLaunch("BuildHeap / remove", doBuildHeapRemove);
    monitoredLaunch("HeapSort", doHeapSort);
    monitoredLaunch("QuickSort", doQuickSort);

    free(data);
    free(dataCopy);
    return 0;
}
