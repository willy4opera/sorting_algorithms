#include <stdio.h>
#include "sort.h"

void element_swap(int *a, int *b);
int partition(int array[], size_t size, int start, int end);
void partition_sort(int array[], size_t size, int start, int end);
/**
 * quick_sort - sort array using quick sort
 * algorithm
 * @array: array to be sorted.
 * @size: array size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	partition_sort(array, size, 0, size - 1);
}

/**
 * element_swap - swap element position in
 * array
 * @a: element to be swaped wit b
 * @b: element to be swaped wit a
 * Return: void
 */
void element_swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Lomuto partition scheme.
 * @size: size
 * @array: array
 * @start: starting pos
 * @end: end pos
 * Return: position of the pivot
 */
int partition(int array[], size_t size, int start, int end)
{
	int i, j;
	int *pivot = &array[end];

	i = start;
	for (j = start; j < end; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				element_swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > *pivot)
	{
		element_swap(&array[i], pivot);
		print_array(array, size);
	}
	return (i);
}

/**
 * partition_sort - Lomuto partition sort.
 * @array: array to be sorted
 * @start: starting indx
 * @end: ending indx
 * @size: array size
 * Return: void
 */
void partition_sort(int array[], size_t size, int start, int end)
{
	int pivot;

	if ((end - start) > 0)
	{
		pivot = partition(array, size, start, end);

		partition_sort(array, size, start, pivot - 1);
		partition_sort(array, size, pivot + 1, end);
	}
}
