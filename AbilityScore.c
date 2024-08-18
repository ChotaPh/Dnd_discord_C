// C program for Merge Sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <process.h>


struct ability_score
{  
    int STR, DEX, CON, WIS, INT, CHA;
    int M_STR, M_DEX, M_CON, M_WIS, M_INT, M_CHA;
};

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(int a[], int l, int r)
{
    if (l < r) {
        // find m = middle of sub-array 
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

// Function to print an array
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Driver code
void get_abilities_arr(int arr[])
{
    int i, j, k;
    int a[4];
    int a_size = sizeof(a) / sizeof(a[0]);

    srand(time(NULL) * _getpid());

    for (k = 0; k < 6; k++)
    {
        int MAX_SCOR = 4;
       

        for(i = 0; i < a_size; i++)
        {
            a[i] = (rand() % 6) + 1;
        }

        mergeSort(a, 0, a_size - 1);
        
        
        int sum = 0;
        for(j = 1; j < a_size; j++)
        {
            sum = sum + a[j];
        }

        arr[k] = sum;

    }

}

// Function to assign ability scores from rolled numbers
void get_abilities_scor(struct ability_score *AB, int arr[], int ab_arr[])
{
    int i, j, input;
    int found;

    printf("Set rolled number to ability score\n");

    for (i = 0; i < 6; i++) 
    {
        do 
        {
            printf("Enter value for ");
            switch (i) 
            { // i case for each index
                case 0: printf("STR: "); break;
                case 1: printf("DEX: "); break;
                case 2: printf("CON: "); break;
                case 3: printf("INT: "); break;
                case 4: printf("WIS: "); break;
                case 5: printf("CHA: "); break;
            }

            fflush(stdout);  // Ensure the output is flushed
            if (scanf("%d", &input) != 1) {
                // If input is not an integer, clear the input buffer
                printf("Invalid input. Please enter a valid number.\n");
                fflush(stdout);  // Ensure the output is flushed
                while(getchar() != '\n');  // Clear the input buffer
                found = 0;
                continue;
            }
            
            found = 0;
            for (j = 0; j < 6; j++) 
            {
                if (input == arr[j]) {
                    found = 1;
                    arr[j] = -1; // Mark as used
                    break;
                }
            }

            if (!found) {
                printf("Invalid input. Do not CHEAT\n");
                fflush(stdout);
            }

        } while (!found);

        switch (i) 
        {
            case 0: AB->STR = input; break;
            case 1: AB->DEX = input; break;
            case 2: AB->CON = input; break;
            case 3: AB->INT = input; break;
            case 4: AB->WIS = input; break;
            case 5: AB->CHA = input; break;
        }

        ab_arr[i] = input;
    }
}

void get_abilities_modifier(struct ability_score *AB)
{
    int i;
    for (i = 0; i < 6; i++)
    {
        switch(i)
        {
            case 0: AB -> M_STR = (AB -> STR - 10) /2; break;
            case 1: AB -> M_DEX = (AB -> DEX - 10) /2; break;
            case 2: AB -> M_CON = (AB -> CON - 10) /2; break;
            case 3: AB -> M_INT = (AB -> INT - 10) /2; break;
            case 4: AB -> M_WIS = (AB -> WIS - 10) /2; break;
            case 5: AB -> M_CHA = (AB -> CHA - 10) /2; break;
        }
    }
    fflush(stdout);
}

int main()
{
    int Ability_Arr[6];
    struct ability_score AB;
    int ab_arr[6];

    get_abilities_arr(Ability_Arr);

    printf("rolled ability score\n");
    printArray(Ability_Arr,6);

    printf("\n");

    get_abilities_scor(&AB, Ability_Arr, ab_arr);
    printf("Assigned ability scores:\n");
    printf("STR: %d, DEX: %d, CON: %d, INT: %d, WIS: %d, CHA: %d\n",
           AB.STR, AB.DEX, AB.CON, AB.INT, AB.WIS, AB.CHA);
    
    printf("\n");
    get_abilities_modifier(&AB);
    printf("Assigned ability modifier:\n");
    printf("STR: %d, DEX: %d, CON: %d, INT: %d, WIS: %d, CHA: %d\n",
           AB.M_STR, AB.M_DEX, AB.M_CON, AB.M_INT, AB.M_WIS, AB.M_CHA);
    
    //wait(10000);
    return 0;
}