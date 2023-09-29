#include "sort.h"

void int_swap(int *a, int *b);
int partition_swp(int *array, size_t size, int left, int right);
void hoare_srt(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * int_swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void int_swap(int *a, int *b)
{
	int var_temp;

	var_temp = *a;
	*a = *b;
	*b = var_temp;
}

/**
 * partition_swp - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the var_pvot.
 * Prints the array after each swap of two elements.
 */
int partition_swp(int *array, size_t size, int left, int right)
{
	int var_pvot, up, down;

	var_pvot = array[right];
	for (up = left - 1, down = right + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < var_pvot);
		do {
			down--;
		} while (array[down] > var_pvot);

		if (up < down)
		{
			int_swap(array + up, array + down);
			print_array(array, size);
		}
	}

	return (up);
}

/**
 * hoare_srt - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_srt(int *array, size_t size, int left, int right)
{
	int var_part;

	if (right - left > 0)
	{
		var_part = partition_swp(array, size, left, right);
		hoare_srt(array, size, left, var_part - 1);
		hoare_srt(array, size, var_part, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_srt(array, size, 0, size - 1);
}
