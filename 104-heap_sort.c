#include "sort.h"

void int_swap(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * int_swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void int_swap(int *a, int *b)
{
	int ver_tem;

	ver_tem = *a;
	*a = *b;
	*b = ver_tem;
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t lft, rght, lrg;

	lft = 2 * root + 1;
	rght = 2 * root + 2;
	lrg = root;

	if (lft < base && array[lft] > array[lrg])
		lrg = lft;
	if (rght < base && array[rght] > array[lrg])
		lrg = rght;

	if (lrg != root)
	{
		int_swap(array + root, array + lrg);
		print_array(array, size);
		max_heapify(array, size, base, lrg);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int numi;

	if (array == 0 || size < 2)
		return;

	for (numi = (size / 2) - 1; numi >= 0; numi--)
		max_heapify(array, size, size, numi);

	for (numi = size - 1; numi > 0; numi--)
	{
		int_swap(array, array + numi);
		print_array(array, size);
		max_heapify(array, size, numi, 0);
	}
}
