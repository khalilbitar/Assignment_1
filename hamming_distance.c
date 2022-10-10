#include <stdio.h>
#include <stdbool.h>

char * decimalToBinary(int);
void printBinary(char *);
int calculateHammingD(char *, char *);

//requires: a positive integer(4 bytes)
//effects: returns an array of bit characters representing the given number in binary
char * decimalToBinary(int a) {
    static char binary[32];
    int i = 31;
    while(a != 0 && i >= 0) {
        binary[i] = (a % 2 == 0) ? '0' : '1';
        a = a / 2;
        i--;
    }
    return binary;
}

//requires: an array of bit characters(at most 32 bits)
//effects: prints the binary number given as argument
void printBinary(char * b) {
    for(int i = 0; i <= 31; i++) {
        printf("%c", b[i]);
    }
    printf("\n");
}

//requires: two arrays of bit characters(only 0's and 1's), i.e., string binary representations of two integers(so 32 bits at most)
//effects: returns the hamming distance between the two integers(that is the number of bits they differ in)
int calculateHammingD(char * b1, char * b2) {
    int counter = 0;
    for(int i = 0; i < 32 ; i++) {
        if(b1[i] != b2[i])
            counter++;
    }
    return counter;
}

//testing strategy: two equal numbers, two numbers that are complements of each other,
int main() {
    while(true) {
        int x;
        char * x1_binary;
        char * x2_binary;
        scanf("%d", &x);
        if(x < 0)
            break;
        x1_binary = decimalToBinary(x);
        printBinary(x1_binary);
        scanf("%d", &x);
        x2_binary = decimalToBinary(x);
        printBinary(x2_binary);
        int hamming_d = calculateHammingD(x1_binary, x2_binary);
        printf("hamming distance: %d\n", hamming_d);
    }
    return 0;
}
