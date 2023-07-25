#include "sort.h"
/**
 * shell_sort - sort an array using shell sort
 * aligorithm and Kruth sequence
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int interval, i, j, k, tmp;

	for (i = 1; i <(int) size - 1; i = i * 3 + 1)
	{
		if (i <(int)size - 1)
			interval = i;
	}
	while (interval > 0)
	{
		for (i = 0; i < interval; i++)
		{
			j = i;
			while (j < (int)size)
			{
				k = j;
				while (k - interval >= i)
				{
					if (array[k] < array[k - interval])
					{
						tmp = array[k - interval];
						array[k - interval] = array[k];
						array[k] = tmp;
					}
					k = k - interval;
				}
				j = j + interval;
			}
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}

