#include "sort.h"
/**
 * selection_sort - sorts an array
 * using selection sort aligorithm
 * @array: the array to be sorted
 * @size: size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	int i, j, min_index,min, tmp;

	for (i = 0; i < ((int)size) - 1; i++)
	{
		min_index = i;
		min = array[i];
		for (j = i + 1; j < (int)size; j++)
		{
			if (array[j] < min)
			{
				min_index = j;
				min = array[j];
			}
		}
		if (min_index != i)
		{
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index] = tmp;
			print_array(array, size);
		}
	}
}
