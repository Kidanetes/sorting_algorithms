#include "sort.h"
#include <stdlib.h>
/**
 * counting_sort - sort an array using
 * counting sort
 * @array: array to be sorted
 * @size: size of an array
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	int *array_copy, *count, max, i, sum = 0;
	int index;

	if ((int)size <= 1 || array == NULL)
		return;
	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	array_copy = malloc(sizeof(int) * size);
	if (count == NULL || array_copy == NULL)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	for (i = 0; i <= max; i++)
	{
		sum += count[i];
		count[i] = sum;
	}
	print_array(count, max + 1);
	for (i = 0; i < (int)size; i++)
	{
		index = count[array[i]] - 1;
		array_copy[index] = array[i];
		/*for (j = array[i]; j <= max; j++)*/
		/*count[i]--;/*/
		count[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = array_copy[i];
	free(count);
	free(array_copy);
}
