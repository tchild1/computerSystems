#include <stdio.h>

int main()
{
    // This is our array of chars
    char s[10];
    int t;
    
    // Input the char values
    for(int i = 0; i < 9; i++){
        scanf("%d", &t); // scan the int 
        s[i] = t;        // save in the char 
    }
    
    s[9] = 0; // Set the NULL character
    
    // Output the array as a C-string
    printf("%s\n", s);

    for(int i = 0; i < 9; i++){
        printf("0x%x\n", s[i]); 
    }

    return 0;
}

// 71 111 32 67 111 117 103 115 33

