#include <stdio.h>

int msb(int);
int lsb(int);
char * decimalToBinary(int);

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

//requires: positive non-zero integer(unsigned int)
//effects: returns the position of msb if x != 0 and -1 if x == 0
int msb(int x) {
    char * xb = decimalToBinary(x);
    for(int i = 31; i >= 0; i--) {
        if(xb[i] == '1')
            return i;
    }
    return -1; //only when x == 0
}

//requires: positive non-zero integer(unsigned int)
//effects: returns the position of lsb if x != 0 and -1 if x == 0
int lsb(int x) {
    char * xb = decimalToBinary(x);
    for(int i = 0; i <= 31; i++) {
        if(xb[i] == '1')
            return i;
    }
    return -1;
}

//testing strategy: test powers of 2, negative integers, 0
int main() {
    int x;
    printf("Enter a number: ");
    scanf("%u", &x);

    printf("distance: %d\n", msb(x)-lsb(x));

    return 0;
}
