/*
 * File: 106-bitonic_sort.c
 * Auth: Odionye Obiajulu Williams
 */

#include "sort.h"

void int_swap(int *a, int *b);
void merg_bitonic(int *array, size_t size, size_t start, size_t seq,
		char flow);
void sep_bitn(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

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
 * merg_bitonic - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */
void merg_bitonic(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t numi, var_jump = seq / 2;

	if (seq > 1)
	{
		for (numi = start; numi < start + var_jump; numi++)
		{
			if ((flow == UP && array[numi] > array[numi + var_jump]) ||
			    (flow == DOWN && array[numi] < array[numi + var_jump]))
				int_swap(array + numi, array + numi + var_jump);
		}
		merg_bitonic(array, size, start, var_jump, flow);
		merg_bitonic(array, size, start + var_jump, var_jump, flow);
	}
}

/**
 * sep_bitn - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void sep_bitn(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		sep_bitn(array, size, start, cut, UP);
		sep_bitn(array, size, start + cut, cut, DOWN);
		merg_bitonic(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sep_bitn(array, size, 0, size, UP);
}
