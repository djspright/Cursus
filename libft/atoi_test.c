#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	printf("%d\n", atoi(av[1]));
}
