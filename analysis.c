#include <stdio.h>
#include <stdlib.h>

void printArray(int[], const int);
int calcFrequency(int[], const int, int);
void arrayHistogram(int[], const int);
void swapValues(int[], const int SIZE, int i, int j);
void bubbleSort(int[], const int);
double median(int[], const int);
int mode(int[], const int);
int isSorted(int[], const int);

//requires: an array of integers(consisting of 1, 2, and 3 only) of constant size
//effects: prints the indexes of the array and their corresponding values in a specific format
void printArray(int array[], const int SIZE) {
    printf("Index Value\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%4d %4d\n", i, array[i]);
    }
}

//requires: an array of integers(consisting of 1, 2, and 3 only) of constant size, and an integer x(1, 2, or 3)
//effects: returns the frequency of x in the array
int calcFrequency(int array[], const int SIZE, int x) {
    int frequency = 0;
    for(int i = 0; i < SIZE; i++) {
        if(array[i] == x)
            frequency++;
    }
    return frequency;
}

//requires: an array of integers(consisting of 1, 2, and 3 only) of constant size
//effects: prints a histogram of the array in a specific format
void arrayHistogram(int array[], const int SIZE) {
    int one_freq = calcFrequency(array, SIZE, 1);
    int two_freq = calcFrequency(array, SIZE, 2);
    int three_freq = calcFrequency(array, SIZE, 3);

    printf("Value Frequency Histogram\n");
    printf("%4d %4d", 1, one_freq);
    char f1[one_freq+1];
    for(int i = 0; i < one_freq; i++) {
        f1[i] = '*';
    }
    f1[one_freq] = '\0';
    printf("%16s\n", f1);

    char f2[two_freq+1];
    printf("%4d %4d", 2, two_freq);
    for(int i = 0; i < two_freq; i++) {
        f2[i] = '*';
    }
    f2[two_freq] = '\0';
    printf("%16s\n", f2);

    char f3[three_freq+1];
    printf("%4d %4d", 3, three_freq);
    for(int i = 0; i < three_freq; i++) {
        f3[i] = '*';
    }
    f3[three_freq] = '\0';
    printf("%16s\n", f3);
}

//requires: an array of integers(consisting of 1, 2, and 3 only) of constant size and two indexes i and j that are <= array's size - 1
//effects: swaps the two values at indexes i and j
void swapValues(int array[], const int SIZE, int i, int j) {
    if(i >= SIZE || j >= SIZE) {
        printf("indexes must be < array size\n");
    }
    else {
        int a_i = array[i];
        array[i] = array[j];
        array[j] = a_i;
    }
}

//requires: an array of constant size
//effects: sorts the given array using bubble sort algorithm
void bubbleSort(int array[], const int SIZE) {
    for(int i = 0; i < SIZE; i++) {
        int k = 0;
        int j = k + 1;
        while(k < SIZE - 1 && j < SIZE) {
            if(array[k] > array[j])
                swapValues(array, SIZE, k, j);
            k++;
            j++;
        }
    }
}

//requires: an integer array of constant size
//effects: returns the median of the array(it also sorts the array)
double median(int array[], const int SIZE) {
    bubbleSort(array, SIZE);
    double m;
    if(SIZE % 2 != 0)
        m = array[SIZE/2];
    else
        m = (array[SIZE/2 - 1] + array[SIZE/2])/2.0;
    return m;
}
//requires: an array of integers of constant size
//effects: returns the mode of the array
int mode(int array[], const int SIZE) {
    int most_freq = array[0];
    for(int i = 1; i < SIZE; i++) {
        if(calcFrequency(array, SIZE, array[i]) > most_freq)
            most_freq = array[i];
    }
    return most_freq;
}

//requires: an array of integers of constant size
//effects: returns 1 if the array is sorted and 0 otherwise
int isSorted(int array[], const int SIZE) {
    for(int i = 0; i < SIZE - 1; i++) {
        for(int j = i + 1; j < SIZE; j++) {
            if(array[i] > array[j])
                return 0;
        }
    }
    return 1;
}

//testing strategy: array of equal elements, sorted array, array in descending order, array of 2 elements of equal frequencies
//array of only negative integers, only positive integers, and mixed positive and negative integers
int main() {
    const int SIZE = 10;
    int array[10] = {1, 1, 1, 1, 1, 2, 2, 2, 3, 3};
    printArray(array, SIZE);
    
    arrayHistogram(array, SIZE);

    swapValues(array, SIZE, 0, SIZE-1);
    printArray(array, SIZE);

    int array1[10] = {2, 1, 5, 8, 7, 10, 0, 3, 9, 4};
    printf("array1: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", array1[i]);
    }
    printf("\n");
    printf("array1 is sorted ? %d\n", isSorted(array1, SIZE));
    bubbleSort(array1, SIZE);
    printf("array1 after sorting: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", array1[i]);
    }
    printf("\n");
    printf("array1 is sorted ? %d\n", isSorted(array1, SIZE));

    int array2[10] = {3, 1, 5, 2, 7, 4, 9, 10, 8, 6};
    printf("array2: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", array2[i]);
    }
    printf("\n");
    double m = median(array2, SIZE);
    printf("array2 after calling median: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", array2[i]);
    }
    printf("\n");
    printf("median: %.3f\n", m);

    int most_freq = mode(array, SIZE);
    printf("mode of array: %d\n", most_freq);

    return 0;
}
