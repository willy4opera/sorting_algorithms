#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - sort array using selection sort
 * algorithm
 * @array: array to be sorted
 * @size: array size
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t pos, i, j;
	int min, tmp;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		pos = i;
		for (j = i + 1; j < size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				pos = j;
			}
		}
		if (pos != i)
		{
			tmp = array[i];
			array[i] = min;
			array[pos] = tmp;
			print_array(array, size);
		}
	}
}
