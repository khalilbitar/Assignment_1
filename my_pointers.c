#include <stdio.h>
#include <stdlib.h>

int compare(char[], char[]);
char * * merge(char * [], char * [], int, int);

//requires: two arrays of sorted strings(in alpha-numerical order) and the size of each array
//effects: returns a merged array of the two arrays
char * * merge(char * a1[], char * a2[], int s1, int s2) {
    char * * result;

}

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

int main() {
    char str1[] = {'a', 'a', 'a', '\0'};
    char str2[] = {'a', 'a', '\0'};

    printf("%d\n", compare(str1, str2));
    return 0;
}
