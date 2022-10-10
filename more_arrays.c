#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 concat(char * *, int);
//requires: 2D array of strings and the number of strings in each array
//effects: returns an array of concatenated strings with a space between them
char * concat(char * * a, int n) {
    char * result[];
    int size = sizeof(a)/sizeof(a[0]);
    for(int i = 0; i < size; i++) {
        result[i] = "";
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < n; j++) {
            result[i] =  strcat(result, a[i][j])
        }
    }
    return result;
} 

//test strategy: array of one string,empty array, array of strings > and < n
int main() {
    char * * a;
    a = {{"I ", "Love ", "Coding"}, {"This ", "Is ", "Sparta"}};
    concat(a, 3);

    return 0;
}