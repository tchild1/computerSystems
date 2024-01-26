#include <stdio.h>

void bubbleSort(int numArray[5]) {
    int swapped = 0;
    do {
        swapped = 0;
        for (int i=0; i<4; i++) {
            if (numArray[i] > numArray[i+1]) {
                int temp = numArray[i];
                numArray[i] = numArray[i+1];
                numArray[i+1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}

int main(int argc, char const *argv[])
{
    // Part 1
    char c = 'a';
    short s = 1;
    int i = 2;
    long l = 3;
    float f = 4.0;
    double d = 5.00;

    char* cp = &c;
    short* sp = &s;
    int* ip = &i;
    long* lp = &l;
    float* fp = &f;
    double* dp = &d;

    // Part 2
    printf("char address: %p\n", cp);
    printf("short address: %p\n", sp);
    printf("int address: %p\n", ip);
    printf("long address: %p\n", lp);
    printf("float address: %p\n", fp);
    printf("double address: %p\n", dp);

    // Part 3
    int charArrayLen = 5;
    int intArray [] = {1, 2, 3, 4, 5};
    char charArray [charArrayLen];
    charArray[2] = 'a';

    // Part 4
    for (int index=0; index<5; index++) {
        int* ip = &intArray[index];
        printf("intArray[%d] address: %p\n", index, ip);
    }

    for (int index=0; index<charArrayLen; index++) {
        char* cp = &charArray[index];
        printf("charArray[%d] address: %p\n", index, cp);
    }

    // Part 5
    int total;
    for (int index=0; index<5; index++) {
        int i;
        scanf("%d", &i);
        total = total + i;
    }
    float average = total/5.0;
    printf("Average: %f\n", average);

    // Part 6
    int numArray[5];
    for (int index=0; index<5; index++) {
        int i;
        scanf("%d", &i);
        numArray[index] = i;
    }

    printf("Unsorted: %d, %d, %d, %d, %d\n", numArray[0], numArray[1], numArray[2], numArray[3], numArray[4]);

    bubbleSort(numArray);

    printf("Sorted: %d, %d, %d, %d, %d\n", numArray[0], numArray[1], numArray[2], numArray[3], numArray[4]);

    return 0;
}
