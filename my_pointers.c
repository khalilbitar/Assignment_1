#include <stdio.h>
#include <stdlib.h>

int compare(char[], char[]);
char * * merge(char * *, char * *, int, int);

//requires: two strings
//effects: returns 1 if str1 <= str2(alpha-numerically) and 0 otherwise
int compare(char str1[], char str2[]) {
    int i = 0;
    int result;
    while(str1[i] != '\0' && str2[i] != '\0') {
        if(str1[i] > str2[i])
            return 0;
        i++;
    }
    if(str1[i-1] == str2[i-1]) {
        if(str2[i] == '\0')
            return 0;
    }
    return 1;
}

char * * merge(char * * a1, char * * a2, int size1, int size2) {
    char * * result;
    int k = 0;
    int i = 0, j = 0;
    while(i < size1 && j < size2 && k < (size1+size2)) {
        if(compare(a1[i], a2[j])) {
            result[k] = a1[i];
            i++;
        } else {
            result[k] = a2[j];
            j++;
        }
        k++;
    }
    return result;
}

int main() {
    char * * a1;
    a1[0] = {'a', 'b', '\0'};
    a1[1] = {'a', 'c', '\0'};
    char * * a2;
    a2[0] = {'z', 'a', '\0'};
    a2[1] = {'z', 'b', '\0'}; 
    a2[2] = {'z', 'z', 'z', 'z', 'c', '\0'};

    char * * result = merge(a1, a2, 3, 4);
    for(int i = 0; i < 6; i++) {
        printf("%s\n", result[i]);
    }

    return 0;
}
