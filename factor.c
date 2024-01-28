#include <stdio.h>
#include <stdlib.h>

/**
 * main - a function that begins the program and factories as many numbers
 * as possible into a product of two smaller numbers.
 *
 * @argc: int
 * @argv: char **
 * Return: int
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned long long n, i;

	if (argc != 2)
	{
		printf("Usage: factors <file>\n");
		return (1);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error opening file.\n");
		return (1);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		n = strtoull(line, NULL, 10);
		for (i = 2; i <= n / i; i++)
		{
			if (n % i == 0)
			{
				printf("%llu=%llu*%llu\n", n, n / i, i);
				break;
			}
		}
		if (i > n / i)
			printf("%llu=%llu*%llu\n", n, 1ull, n);
	}
	fclose(file);
	if (line)
		free(line);
	return (0);
}
