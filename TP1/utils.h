#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void permut(int *a, int *b);
void print_data(int *tableau, int taille);
void read_data(int argc, char **argv, int **dataout, int *n, int *k);
void start_clock();
double get_clock_time_in_ms();
void monitorLaunch(char *title);
void monitorStop();
void bubbleSort(int *tableau, int n, int k);
#endif