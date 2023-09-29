#include "sort.h"

void swap_ints(int *numa, int *numb);
int lomuto_partition(int *arry_, size_t size, int lft, int right);
void lomuto_sort(int *arry_, size_t size, int lft, int right);
void quick_sort(int *arry_, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *numa, int *numb)
{
	int temp_var;

	temp_var = *numa;
	*numa = *numb;
	*numb = temp_var;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @arry_: The array of integers.
 * @size: The size of the array.
 * @lft: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *arry_, size_t size, int lft, int right)
{
	int *pvt, abv, blw;

	pvt = arry_ + right;
	for (abv = blw = lft; blw < right; blw++)
	{
		if (arry_[blw] < *pvt)
		{
			if (abv < blw)
			{
				swap_ints(arry_ + blw, arry_ + abv);
				print_array(arry_, size);
			}
			abv++;
		}
	}

	if (arry_[abv] > *pvt)
	{
		swap_ints(arry_ + abv, pvt);
		print_array(arry_, size);
	}

	return (abv);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @arry_: An array of integers to sort.
 * @size: The size of the array.
 * @lft: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *arry_, size_t size, int lft, int right)
{
	int part_var;

	if (right - lft > 0)
	{
		part_var = lomuto_partition(arry_, size, lft, right);
		lomuto_sort(arry_, size, lft, part_var - 1);
		lomuto_sort(arry_, size, part_var + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @arry_: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *arry_, size_t size)
{
	if (arry_ == 0 || size < 2)
		return;

	lomuto_sort(arry_, size, 0, size - 1);
}
