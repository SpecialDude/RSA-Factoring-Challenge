#include <stdio.h>
#include <stdlib.h>
#include "BigInt.h"

/**
 * open_file - Open up a file for reading
 *
 * @filename: file to open
 *
 * Return: FILE*
 */
FILE *open_file(char *filename)
{
	FILE *fd;

	fd = fopen(filename, "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * readline - Read content from a file stream
 *
 * @fd: File Stream
 *
 * Return: char*
 */
char *readline(FILE *fd)
{
	char c;
	int i = 0;
	char *line;
	int bufsize = 60;
	int size;

	line = malloc(sizeof(char) * bufsize);

	while ((c = fgetc(fd)) != EOF)
	{
		if (c == '\n')
		{
			*(line + i) = '\0';
			return (line);
		}

		*(line + i) = c;

		i++;

		if (i > bufsize)
		{
			bufsize += bufsize;
			line = realloc(line, sizeof(char) * bufsize);
		}
	}

	if (i != 0)
	{
		*(line + i) = '\0';
		return (line);
	}

	free(line);
	return (NULL);
}

int main(int ac, char **av)
{
    char *filename, *eptr;
    FILE *fd;
    char *line;
    unsigned long long number, i, j, k, l, mid, third;

    if (ac != 2)
        exit(EXIT_FAILURE);

    filename = av[1];

    fd = open_file(filename);

	while ((line = readline(fd)) != NULL)
	{

        number = strtoull(line, &eptr, 10);

		if (number % 2 == 0)
		{
			printf("%llu=%llu*%llu\n", number, number/2, 2);
			free(line);
			continue;
		}


		mid = number / 2;
		third = 3 * number / 4;

		mid = (mid % 2 == 1) ? mid : mid + 1;
		third = (third % 2 == 1) ? third : third + 1;

        i = 3;			// Increasing
		j = mid; // Decreasing
		k = mid + 2;		// Increasing   3 * number / 4
		l = number - 2;


        while ((i <= (mid/2) + 1 && j > (mid/2) + 1) || (k <= third && l > third))
        {
			// printf("(%llu	%llu) <----> (%llu	%llu)\n", i, j, k, l);
            if (number % i == 0)
            {
                printf("%llu=%llu*%llu\n", number, number/i, i);
                break;
            }

            if (number % j == 0)
            {
                printf("%llu=%llu*%llu\n", number, j, number/j);
                break;
            }

			if (number % k == 0)
            {
                printf("%llu=%llu*%llu\n", number, number/k, k);
                break;
            }

            if (number % l == 0)
            {
                printf("%llu=%llu*%llu\n", number, l, number/l);
                break;
            }

            i += 2;
            j -= 2;
			k += 2;
			l -= 2;
        }

		free(line);
	}

	fclose(fd);

}