#include "sort.h"
#include <stdlib.h>
void divide(int *array, int p, int q);
void merge(int *array, int p, int q, int r);
/**
 * merge_sort - sort an array using
 * merge sort
 * @array: array to be sorted
 * @size: size of an array
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || (int)size <= 1)
		return;
	divide(array, 0, (int)size - 1);
}
/**
 * divide - divide an array into
 * sub arrays
 * @array: array to be sorted
 * @p: left bound
 * @q: right bound
 * Return: nothing
 */
void divide(int *array, int p, int q)
{
	int left;

	if (p < q)
	{
		left = p + (q - p - 1) / 2;
		divide(array, p, left);
		divide(array, left + 1, q);
		merge(array, p, left, q);
	}
}
/**
 * merge - merge two sub arrays
 * @array: array to be sorted
 * @p: left bound
 * @r: medium bound
 * @q: right bound
 * Return: nothing
 */
void merge(int *array, int p, int q, int r)
{
	int i, j, tmp, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(&(array[p]), q - p + 1);
	printf("[right]: ");
	print_array(&(array[q + 1]), r - q);
	printf("[Done]: ");

	i = p;
	j = q + 1;
	while (i <= q && j <= r)
	{
		if (array[i] > array[j])
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			k = j;
			for (; k < r; k++)
			{
				if (array[k] > array[k + 1])
				{
					tmp = array[k + 1];
					array[k + 1] = array[k];
					array[k] = tmp;
				}
			}
			i++;
			continue;
		}
		i++;
		j++;
	}
	print_array(&(array[p]), r - p + 1);
}
