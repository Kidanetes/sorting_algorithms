#include "sort.h"
/**
 * quick_sort - sort an array using
 * quick sort aligorithm
 * @array: array to be sorted
 * @size: size of an array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort2(array, array, size, size);
}
/**
 * quick_sort2 - sort an array using
 * quicksort aligorithm
 * @array: array to be sorted
 * @new_array: array after partitioned
 * @new_size: size of a partitoin
 * @size: size of an array
 */
void quick_sort2(int *array, int *new_array, size_t new_size, size_t size)
{
	int pivot = new_array[(int)new_size - 1];
	int i, j = 0, tmp;

	if (new_size <= 1)
		return;

	for (i = 0; i < (int)new_size; i++)
	{
		if (new_array[i] <= pivot)
		{
			tmp = new_array[j];
			new_array[j] = new_array[i];
			new_array[i] = tmp;
			j++;
			print_array(array, size);
		}
	}
	j--;
	/*tmp = new_array[j];
	new_array[j] = pivot;
	new_array[i] = tmp;
	print_array(array, size);*/
	quick_sort2(array, new_array, j, size);
	quick_sort2(array, &new_array[j + 1], (int)new_size - j - 1, size);
}
