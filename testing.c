#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	char *test;

	test = malloc(2);
	test[0] = 'a';
	test[1] = '\0';
	printf("|%2.c|\n", 'a');
	/*
	printf("|%2d|\n", 1);
	printf("|%2s|\n", "a");
	printf("|%20.20p|\n", test);
	printf("|%2c|\n", 'a');
	printf("|%2%|\n");*/
	return (0);
}