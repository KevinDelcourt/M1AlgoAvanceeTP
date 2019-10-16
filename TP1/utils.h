#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Activity
{
    int nbPermut;
    double timeSpent;
};

void permut(int *a, int *b);
void print_data(int *tableau, int taille);
void reverse_print_data(int *tableau, int taille, int taille_max);
void read_data(int argc, char **argv, int **dataout, int *n, int *k);
void start_clock();
double get_clock_time_in_ms();
void monitorLaunch(char *title);
struct Activity monitorStop();
void bubbleSort(int *tableau, int n, int k);
void quickSort(int *tableau, int first, int last);
void arrayCopy(int *source, int **destination, int size);
#endif