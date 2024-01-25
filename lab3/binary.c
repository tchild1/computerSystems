#include <stdio.h>

int main()
{

    // This is our char being converted
    unsigned char c = '!';
    int bitArray[8];

    int index=7;
    for (int i=0; i<8; i++) {
        if (c % 2 == 1) {
            bitArray[index] = 1;
        } else {
            bitArray[index] = 0;
        }
        index--;
        c = c / 2;
    }

    for (int i=0; i<8; i++) {
        printf("%d", bitArray[i]);
    }
    printf("\n");


    return 0;
}    
    
