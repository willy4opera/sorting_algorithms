#include "sort.h"

int max_func(int *array, int size);
void radix_counting_sort(int *array, size_t size, int var_sig, int *buffer);
void radix_sort(int *array, size_t size);

/**
 * max_func - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int max_func(int *array, int size)
{
	int var_max, numi;

	for (var_max = array[0], numi = 1; numi < size; numi++)
	{
		if (array[numi] > var_max)
			var_max = array[numi];
	}

	return (var_max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @var_sig: The significant digit to sort on.
 * @buffer: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int var_sig, int *buffer)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t numi;

	for (numi = 0; numi < size; numi++)
		count[(array[numi] / var_sig) % 10] += 1;

	for (numi = 0; numi < 10; numi++)
		count[numi] += count[numi - 1];

	for (numi = size - 1; (int)numi >= 0; numi--)
	{
		buffer[count[(array[numi] / var_sig) % 10] - 1] = array[numi];
		count[(array[numi] / var_sig) % 10] -= 1;
	}

	for (numi = 0; numi < size; numi++)
		array[numi] = buffer[numi];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int var_max, var_sig, *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	var_max = max_func(array, size);
	for (var_sig = 1; var_max / var_sig > 0; var_sig *= 10)
	{
		radix_counting_sort(array, size, var_sig, buffer);
		print_array(array, size);
	}

	free(buffer);
}
