#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
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
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *var_sorted, var_max, numi;

	if (array == NULL || size < 2)
		return;

	var_sorted = malloc(sizeof(int) * size);
	if (var_sorted == NULL)
		return;
	var_max = get_max(array, size);
	count = malloc(sizeof(int) * (var_max + 1));
	if (count == NULL)
	{
		free(var_sorted);
		return;
	}

	for (numi = 0; numi < (var_max + 1); numi++)
		count[numi] = 0;
	for (numi = 0; numi < (int)size; numi++)
		count[array[numi]] += 1;
	for (numi = 0; numi < (var_max + 1); numi++)
		count[numi] += count[numi - 1];
	print_array(count, var_max + 1);

	for (numi = 0; numi < (int)size; numi++)
	{
		var_sorted[count[array[numi]] - 1] = array[numi];
		count[array[numi]] -= 1;
	}

	for (numi = 0; numi < (int)size; numi++)
		array[numi] = var_sorted[numi];

	free(var_sorted);
	free(count);
}
