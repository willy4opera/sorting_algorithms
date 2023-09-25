#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - sort linked list using insertion sort
 * algorithm
 * @list: linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *tmp;

	if (*list == NULL || (*list)->next == NULL)
		return;


	for (ptr = (*list)->next; ptr != NULL; ptr = ptr->next)
	{
		tmp = ptr;
		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;
			tmp->next->prev = tmp;
			if (tmp->prev == NULL)
				*list = tmp;
			else
				tmp->prev->next = tmp;
			print_list(*list);
		}
	}
}
