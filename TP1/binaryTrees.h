#ifndef BINARYTREES_H_INCLUDED
#define BINARYTREES_H_INCLUDED
#include <math.h>
#include "utils.h"
struct BinaryTree
{
    int *data;
    int tailleMax;
    int tailleRemplie;
};

int prioritaire(int a, int b);
int left(int i);
int right(int i);
int parent(int i);
void percolate_down(struct BinaryTree arbre, int i);
void percolate_up(struct BinaryTree arbre, int i);
void add(struct BinaryTree *arbre, int value);
int removeMax(struct BinaryTree *arbre);
struct BinaryTree buildHeap(int *tableau, int n);
struct BinaryTree buildHeapSuccessiveAdd(int *tableau, int *output, int n);
int tailleMaxBtreePourHauteur(int h);
void printBinaryTree(struct BinaryTree btree);
int validateBtree(struct BinaryTree btree);
void heapSort(struct BinaryTree *btree, int n);
#endif