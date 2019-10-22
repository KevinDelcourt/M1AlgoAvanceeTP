#include "binaryTrees.h"
#include <math.h>
#include "utils.h"

#define AFFICHAGE_MAX 4
#define ERREUR_TAILLE_REMPLIE_SUP_TAILLE_MAX 2
#define ERREUR_BROKEN_TREE 1

int prioritaire(int a, int b)
{
    return a > b;
}

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
    if (left(i) < arbre.tailleRemplie && prioritaire(arbre.data[left(i)], arbre.data[i]))
    {
        m = left(i);
    }
    else
    {
        m = i;
    }

    if (right(i) < arbre.tailleRemplie && prioritaire(arbre.data[right(i)], arbre.data[m]))
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
    while (i > 0 && prioritaire(arbre.data[i], arbre.data[j]))
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

int tailleMaxBtreePourHauteur(int h)
{
    return pow(2, h + 1) - 1;
}

void printBinaryTree(struct BinaryTree btree)
{
    int currentLevel = 0;
    int n = btree.tailleRemplie;
    char *valide = (validateBtree(btree) == 0 ? "\033[0;32mValide\033[0m" : "\033[0;31mCassé\033[0m");
    printf("Arbre de taille %d/%d (%s): \n", btree.tailleRemplie, btree.tailleMax, valide);
    if (n > tailleMaxBtreePourHauteur(AFFICHAGE_MAX))
    {
        printf("\033[0;33mGrande taille:\033[0m seul les %d premiers niveaux sont affichés.\n", AFFICHAGE_MAX);
        n = tailleMaxBtreePourHauteur(AFFICHAGE_MAX);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", btree.data[i]);
        if ((i + 1) == tailleMaxBtreePourHauteur(currentLevel))
        {
            printf("\n");
            currentLevel++;
        }
        else if (i == n - 1)
        {
            printf("\n");
        }
    }
}

int validateBtree(struct BinaryTree btree)
{
    if (btree.tailleRemplie > btree.tailleMax)
        return ERREUR_TAILLE_REMPLIE_SUP_TAILLE_MAX;
    for (int i = 0; i < btree.tailleRemplie; i++)
    {
        if (left(i) < btree.tailleRemplie && prioritaire(btree.data[left(i)], btree.data[i]))
            return ERREUR_BROKEN_TREE;
        else if (right(i) < btree.tailleRemplie && prioritaire(btree.data[right(i)], btree.data[i]))
            return ERREUR_BROKEN_TREE;
    }
    return 0;
}

void heapSort(struct BinaryTree *btree, int n)
{
    for (int i = 0; i < n; i++)
    {
        permut(&btree->data[0], &btree->data[btree->tailleRemplie - 1]);

        btree->tailleRemplie--;
        percolate_down(*btree, 0);
    }
}