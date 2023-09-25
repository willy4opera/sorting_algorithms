#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - sort array using bubble sort
 * algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int changed, tmp;
	size_t i;

	if (array == NULL || size == 1)
		return;

	do {
		changed = 0;

		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				changed = 1;
				print_array(array, size);
			}
		}
	} while (changed);

}
