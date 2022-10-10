#include <stdio.h>
#include <stdlib.h>

void printArray(const int[], const int);
int calcFrequency(const int[], const int, int);
void arrayHistogram(const int[], const int);

//requires: a constant array of integers of constant size
//effects: prints the indexes of the array and their corresponding values in a specific format
void printArray(const int array[], const int SIZE) {
    printf("Index Value\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%4d %4d\n", i, array[i]);
    }
}

//requires: a constant array of integers of constant size, and an integer x
//effects: returns the frequency of x in the array
int calcFrequency(const int[] array, const int SIZE, int x) {
    int frequency = 0;
    for(int i = 0; i < SIZE; i++) {
        if(array[i] == x)
            frequency++;
    }
    return frequency;
}



int main() {
    const int SIZE = 10;
    const int array[10] = {1, 1, 1, 1, 1, 2, 2, 2, 3, 3};
    printArray(array, SIZE);
    
    return 0;
}