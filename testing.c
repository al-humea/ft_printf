#include <stdio.h>
#include <stdlib.h>

unsigned long	ft_hexalen(unsigned long nbr)
{
	unsigned long i;

	i = 0;
	while (nbr >= 16)
	{
		nbr/= 16;
		i++;
	}
	return (i + 1);
}

int main(void)
{
	printf("%lu\n",ft_hexalen(256));
/*	char *test;

	test = malloc(1);
	printf("|%2d|\n", 1);
	printf("|%2s|\n", "a");
	printf("|%20.20p|\n", test);
	printf("|%2c|\n", 'a');
	printf("|%2%|\n");*/
	return (0);
}