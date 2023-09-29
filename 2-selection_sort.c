#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmpr_v;

	tmpr_v = *a;
	*a = *b;
	*b = tmpr_v;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min_val;
	size_t numi, numj;

	if (array == 0 || size < 2)
		return;

	for (numi = 0; numi < size - 1; numi++)
	{
		min_val = array + numi;
		for (numj = numi + 1; numj < size; numj++)
			min_val = (array[numj] < *min_val) ? (array + numj) : min_val;

		if ((array + numi) != min_val)
		{
			swap_ints(array + numi, min_val);
			print_array(array, size);
		}
	}
}
