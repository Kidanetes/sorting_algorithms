#include "sort.h"
#include <stdlib.h>
void sort(int *array, int *digit, int *index, size_t size);
/**
 * radix_sort - sort an array using radix
 * sort aligorithm
 * @array: array to be sorted
 * @size: size of an array
 * Reurn: nothing
 */
void radix_sort(int *array, size_t size)
{
	int max, i, j, count = 1;
	int *digit, *index;

	if (array == NULL || size <= 1)
		return;
	digit = malloc(sizeof(int) * (int)size);
	index = malloc(sizeof(int) * (int)size);
	if (digit == NULL || index == NULL)
		return;
	max = array[0];
	index[0] = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
		index[i] = array[i];
	}
	j = max;
	while (j / 10 != 0)
	{
		count++;
		j = j / 10;
	}
	while (count > 0)
	{
		for (i = 0; i < (int)size; i++)
		{
			digit[i] = index[i] % 10;
			index[i] = index[i] / 10;
		}
		sort(array, digit, index, size);
		print_array(array, size);
		count--;
	}
	free(digit);
	free(index);
}

/**
 * sort - sort an array using selection sort
 * based on the siginficant digit of numbers
 * @array: array
 * @digit: digit
 * @index: index
 * @size: size
 * Return: nothing
 */
void sort(int *array, int *digit, int *index, size_t size)
{
	int i, j, status, tmp;

	for (j = 0; j < ((int)size) - 1; j++)
	{
		status = 0;
		for (i = 0; i < (int)size - 1; i++)
		{
			if (digit[i] > digit[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				tmp = index[i];
				index[i] = index[i + 1];
				index[i + 1] = tmp;
				tmp = digit[i];
				digit[i] = digit[i + 1];
				digit[i + 1] = tmp;
				status = 1;
			}
		}
		if (status == 0)
			break;
	}
}
