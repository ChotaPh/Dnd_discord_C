#ifndef ABILITY_SCORE_H
#define ABILITY_SCORE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <process.h>

// Structure definition
struct ability_score
{  
    int STR, DEX, CON, WIS, INT, CHA;
    int M_STR, M_DEX, M_CON, M_WIS, M_INT, M_CHA;
};

// Function declarations
void merge(int a[], int l, int m, int r);
void mergeSort(int a[], int l, int r);
void printArray(int A[], int size);
void get_abilities_arr(int arr[]);
void get_abilities_scor(struct ability_score *AB, int arr[], int ab_arr[]);
void get_abilities_modifier(struct ability_score *AB);

#endif // ABILITY_SCORE_H