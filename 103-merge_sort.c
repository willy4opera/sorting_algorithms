#include "sort.h"

void mg_sub(int *v_subar, int *buffer, size_t front, size_t mid,
		size_t back);
void mg_sort_rcurs(int *v_subar, int *buffer, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * mg_sub - Sort a v_subaray of integers.
 * @v_subar: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void mg_sub(int *v_subar, int *buffer, size_t front, size_t mid,
		size_t back)
{
	size_t vari, varj, vark = 0;

	printf("Merging...\n[left]: ");
	print_array(v_subar + front, mid - front);

	printf("[right]: ");
	print_array(v_subar + mid, back - mid);

	for (vari = front, varj = mid; vari < mid && varj < back; vark++)
		buffer[vark] = (v_subar[vari] < v_subar[varj]) ?
			v_subar[vari++] : v_subar[varj++];
	for (; vari < mid; vari++)
		buffer[vark++] = v_subar[vari];
	for (; varj < back; varj++)
		buffer[vark++] = v_subar[varj];
	for (vari = front, vark = 0; vari < back; vari++)
		v_subar[vari] = buffer[vark++];

	printf("[Done]: ");
	print_array(v_subar + front, back - front);
}

/**
 * mg_sort_rcurs - Implement the merge sort algorithm through recursion.
 * @v_subar: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void mg_sort_rcurs(int *v_subar, int *buffer, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		mg_sort_rcurs(v_subar, buffer, front, mid);
		mg_sort_rcurs(v_subar, buffer, mid, back);
		mg_sub(v_subar, buffer, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	mg_sort_rcurs(array, buffer, 0, size);

	free(buffer);
}
