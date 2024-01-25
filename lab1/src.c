#include <stdio.h>

int main(int argc, char *argv[])
{

	int first = 270;
	int second = 289;

	int result = (first & second) - (first >> 4) - ((second & 0x20) >> 1);

	printf("My name is Tanner Child\n");
	printf("The first number is %d\nThe second number is %d\n", first, second);
	printf("The result is %d\n", result);

	return 0;
}
