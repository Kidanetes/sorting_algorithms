#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {1};
    /*size_t n = sizeof(array) / sizeof(array[0]);*/

    print_array(array, 1);
    printf("\n");
    quick_sort(array, 1);
    printf("\n");
    print_array(array, 1);
    return (0);
}
