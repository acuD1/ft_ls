#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int i = 1;
	struct stat db;

	while (i < ac)
	{
		lstat(av[i], &db);
		printf("ID = %d\n", db.st_dev);
		printf("size = %d\n", minor(db.st_rdev));
		i++;
	}
	return (0);
}
