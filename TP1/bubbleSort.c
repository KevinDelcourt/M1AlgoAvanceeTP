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

void monitorEveryPossibleK()
{
    FILE *f_out_time, *f_out_permut;
    f_out_time = fopen("time.csv", "w");
    f_out_permut = fopen("permut.csv", "w");

    fprintf(f_out_time, "k,BubbleSort partiel,BuildHeap / Remove,HeapSort\n");
    fprintf(f_out_permut, "k,BubbleSort partiel,BuildHeap / Remove,HeapSort\n");
    struct Activity activity;
    for (k = 1; k <= n; k++)
    {
        printf("\nRecherche des %d plus grands éléments du tableau de taille %d : \n", k, n);
        activity = monitoredLaunch("BubbleSort partiel", doBubbleSort);
        fprintf(f_out_time, "%d,%.7f,", k, activity.timeSpent);
        fprintf(f_out_permut, "%d,%d,", k, activity.nbPermut);
        activity = monitoredLaunch("BuildHeap / remove", doBuildHeapRemove);
        fprintf(f_out_time, "%.7f,", activity.timeSpent);
        fprintf(f_out_permut, "%d,", activity.nbPermut);
        activity = monitoredLaunch("HeapSort", doHeapSort);
        fprintf(f_out_time, "%.7f\n", activity.timeSpent);
        fprintf(f_out_permut, "%d\n", activity.nbPermut);
    }
    fclose(f_out_time);
    fclose(f_out_permut);
}

void monitorForCurrentK()
{
    printf("\nRecherche des %d plus grands éléments du tableau de taille %d : \n", k, n);
    monitoredLaunch("BubbleSort partiel", doBubbleSort);
    monitoredLaunch("BuildHeap / remove", doBuildHeapRemove);
    monitoredLaunch("HeapSort", doHeapSort);
    monitoredLaunch("QuickSort", doQuickSort);
}

int main(int argc, char **argv)
{

    read_data(argc, argv, &data, &n, &k);
    //read_worst_case_data(argc, argv, &data, &n, &k);
    printf("Données : \n");
    print_data(data, n);

    //monitorEveryPossibleK();
    monitorForCurrentK();

    free(data);
    free(dataCopy);
    return 0;
}
