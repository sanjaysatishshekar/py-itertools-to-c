#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itertools.h"

int main()
{

	int n;
	scanf("%d", &n);
	int* a = (int*) malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int r;
	scanf("%d", &r);

	iter* i = combinations(a, n, r, sizeof(*a));
	if (!i)
	{
		printf("Invalid input.\n");
		return 1;
	}

	int* c;
	printf("Combinations are \n");
	while (has_next(i))
	{
		c = (int*) next(i);
		for (int j = 0; j < r; j++)
		{
			printf("%d ", c[j]);
		}
		printf("\n");
	}
	free_iter(i);

	iter* i2 = combinations_replacement(a, n, r, sizeof(*a));
	if (!i2)
	{
		printf("Invalid input.\n");
		return 1;
	}

	printf("Combinations with repetitions are \n");
	while (has_next(i2))
	{
		c = (int*) next(i2);
		for (int j = 0; j < r; j++)
		{
			printf("%d ", c[j]);
		}
		printf("\n");
	}
	free_iter(i2);
}
