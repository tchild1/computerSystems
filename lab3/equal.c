#include <stdio.h>

void intAndString() {
    unsigned char u = 51;
    unsigned char c = '3';
    printf("u=%d\n", u);
    printf("c=%c\n", c);

    if (u == c) {
        printf("They are the same!\n");
    } else {
        printf("They are different!\n");
    }
}

void hexAndString() {
    unsigned char u = 0x33;
    unsigned char c = '3';
    printf("u=0x%x\n", u);
    printf("c=%c\n", c);

    if (u == c) {
        printf("They are the same!\n");
    } else {
        printf("They are different!\n");
    }
}

void hexAndInt() {
    unsigned char u = 51;
    unsigned char c = 0x33;
    printf("u=0x%d\n", u);
    printf("c=%x\n", c);

    if (u == c) {
        printf("They are the same!\n");
    } else {
        printf("They are different!\n");
    }
}


int main()
{
    // Task 1
    intAndString();
    hexAndString();
    hexAndInt();

    // Task 2
    int i = 47;
    char c = 'c';
    char string[] = "string";
    int hex = 0x3f3;

    printf("int %d\n", i);
    printf("char %c\n", c);
    printf("string %s\n", string);
    printf("hex %x\n", hex);
    
    return 0;
}
