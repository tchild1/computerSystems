#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define BAD_NUMBER_ARGS 1

/**
 * Parses the command line.
 *
 * argc: the number of items on the command line (and length of the
 *       argv array) including the executable
 * argv: the array of arguments as strings (char* array)
 * bits: the integer value is set to TRUE if bits output indicated
 *       outherwise FALSE for hex output
 *
 * returns the input file pointer (FILE*)
 **/
FILE *parseCommandLine(int argc, char **argv, int *bits) {
  if (argc > 2) {
    printf("Usage: %s [-b|-bits]\n", argv[0]);
    exit(BAD_NUMBER_ARGS);
  }

  if (argc == 2 &&
      (strcmp(argv[1], "-b") == 0 || strcmp(argv[1], "-bits") == 0)) {
    *bits = TRUE;
  } else {
    *bits = FALSE;
  }

  return stdin;
}

void printACharacterAsBits(unsigned char c) {
  int bitArray[8];

  int index=7;
  for (int indx=0; indx<8; indx++) {
    if (c % 2 == 1) {
      bitArray[index] = 1;
    } else {
      bitArray[index] = 0;
    }
    index--;
    c = c / 2;
  }

  for (int indx=0; indx<8; indx++) {
    printf("%d", bitArray[indx]);
  }
    
  printf(" ");
}

/**
 * Writes data to stdout in hexadecimal.
 *
 * See myxxd.md for details.
 *
 * data: an array of no more than 16 characters
 * size: the size of the array
 **/
void printDataAsHex(unsigned char *data, size_t size) {
  int space = 0;
  printf(" ");
  for (int index=0; index<size; index++) {
    if (space) {
      printf("%02x ", data[index]);
      space = 0;
    } else {
      printf("%02x", data[index]);
      space = 1;
    }
  }

  for (int index=0; index<16-size; index++) {
    printf("  ");
    if (space) {
      printf(" ");
      space = 0;
    } else {
      space = 1;
    }
  }
}

/**
 * Writes data to stdout as characters.
 *
 * See myxxd.md for details.
 *
 * data: an array of no more than 16 characters
 * size: the size of the array
 **/
void printDataAsChars(unsigned char *data, size_t size) {
  for (int index=0; index<size; index++) {
    if (data[index] > 126 || data[index] < 32) {
      printf(".");
    } else {
      printf("%c", data[index]);
    }
  }
}

void printDataAsBits(unsigned char *data, size_t numBytesRead) {   
  printf(" ");

  for (int index=0; index<numBytesRead; index++) {
    printACharacterAsBits(data[index]);
  }

  for (int index=0; index<6-numBytesRead; index++) {
    printf("         ");
  }
  printf(" ");
}

void readAndPrintInputAsHex(FILE *input) {
  unsigned char data[16];
  int numBytesRead = fread(data, 1, 16, input);
  unsigned int offset = 0;
  while (numBytesRead != 0) {
    printf("%08x:", offset);
    offset += numBytesRead;
    printDataAsHex(data, numBytesRead);
    printf(" ");
    printDataAsChars(data, numBytesRead);
    printf("\n");
    numBytesRead = fread(data, 1, 16, input);
  }
}

/**
 * Bits output for xxd.
 *
 * See myxxd.md for details.
 *
 * input: input stream
 **/
void readAndPrintInputAsBits(FILE *input) {
  unsigned char data[6];
  int numBytesRead = fread(data, 1, 6, input);
  unsigned int offset = 0;
  while (numBytesRead != 0) {
    printf("%08x:", offset);
    offset += numBytesRead;
    printDataAsBits(data, numBytesRead);
    printDataAsChars(data, numBytesRead);
    printf("\n");
    numBytesRead = fread(data, 1, 6, input);
  }
}

int main(int argc, char **argv) {
  int bits = FALSE;
  FILE *input = parseCommandLine(argc, argv, &bits);

  if (bits == FALSE) {
    readAndPrintInputAsHex(input);
  } else {
    readAndPrintInputAsBits(input);
  }
  return 0;
}
