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
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t num, length = size;
	bool bbly = false;

	if (array == NULL || size < 2)
		return;

	while (bbly == false)
	{
		bbly = true;
		for (num = 0; num < length - 1; num++)
		{
			if (array[num] > array[num + 1])
			{
				swap_ints(array + num, array + num + 1);
				print_array(array, size);
				bbly = false;
			}
		}
		length--;
	}
}
