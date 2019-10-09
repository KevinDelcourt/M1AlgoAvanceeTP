#include "binaryTrees.h"
#include <math.h>
#include "utils.h"

int left(int i)
{
    return 2 * i + 1;
}

int right(int i)
{
    return 2 * i + 2;
}

int parent(int i)
{
    return floor((i - 1) / 2);
}

void percolate_down(struct BinaryTree arbre, int i)
{
    int m;
    if (left(i) < arbre.tailleRemplie && arbre.data[i] < arbre.data[left(i)])
    {
        m = left(i);
    }
    else
    {
        m = i;
    }

    if (right(i) < arbre.tailleRemplie && arbre.data[m] < arbre.data[right(i)])
        m = right(i);

    if (m != i)
    {
        permut(&arbre.data[i], &arbre.data[m]);
        percolate_down(arbre, m);
    }
}

void percolate_up(struct BinaryTree arbre, int i)
{
    int j = parent(i);
    while (i > 0 && arbre.data[j] < arbre.data[i])
    {
        permut(&arbre.data[i], &arbre.data[j]);
        i = j;
        j = parent(i);
    }
}

void add(struct BinaryTree *arbre, int value)
{
    if (arbre->tailleRemplie < arbre->tailleMax)
    {
        arbre->data[arbre->tailleRemplie] = value;
        percolate_up(*arbre, arbre->tailleRemplie);
        arbre->tailleRemplie++;
    }
    else
    {
        printf("\n Tentative d'ajout sur un tableau plein! \n");
    }
}

int removeMax(struct BinaryTree *arbre)
{
    int max = arbre->data[0];
    arbre->data[0] = arbre->data[arbre->tailleRemplie - 1];
    arbre->tailleRemplie--;
    percolate_down(*arbre, 0);
    return max;
}

struct BinaryTree buildHeap(int *tableau, int n)
{
    struct BinaryTree btree = {tableau, n, n};
    for (int i = floor(n / 2) - 1; i >= 0; i--)
    {
        percolate_down(btree, i);
    }
    return btree;
}

struct BinaryTree buildHeapSuccessiveAdd(int *tableau, int *output, int n)
{
    struct BinaryTree btree = {output, n, 0};
    for (int i = 0; i < btree.tailleMax; i++)
    {
        add(&btree, tableau[i]);
    }
    return btree;
}

//TODO -> fonction print arbre -> par niveau -> refuse si tailleRemplie trop grand