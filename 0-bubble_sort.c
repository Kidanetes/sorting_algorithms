#include "sort.h"

/**
 * bubble_sort - sort an array using
 * bubble sort algorithm
 * @array: array to be sorted
 * @size: size of an array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int i, j, status, tmp;

	for (i = 0; i < ((int)size) - 1; i++)
	{
		status = 0;
		for (j = 0; j < ((int)size) - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				status = 1;
				print_array(array, size);
			}
		}
		if (status == 0)
			break;
	}
}
