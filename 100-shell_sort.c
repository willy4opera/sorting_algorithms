#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp_var;

	temp_var = *a;
	*a = *b;
	*b = temp_var;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap_var, numi, numj;

	if (array == NULL || size < 2)
		return;

	for (gap_var = 1; gap_var < (size / 3);)
		gap_var = gap_var * 3 + 1;

	for (; gap_var >= 1; gap_var /= 3)
	{
		for (numi = gap_var; numi < size; numi++)
		{
			numj = numi;
			while (numj >= gap_var && array[numj - gap_var] > array[numj])
			{
				swap_ints(array + numj, array + (numj - gap_var));
				numj -= gap_var;
			}
		}
		print_array(array, size);
	}
}
