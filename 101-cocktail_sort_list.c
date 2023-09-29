#include "sort.h"

void node_swap(listint_t **list, listint_t **tail, listint_t **shaker);
void bhind_ndswap(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * node_swap - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void node_swap(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *var_temp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = var_temp;
	else
		*list = var_temp;
	var_temp->prev = (*shaker)->prev;
	(*shaker)->next = var_temp->next;
	if (var_temp->next != NULL)
		var_temp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = var_temp;
	var_temp->next = *shaker;
	*shaker = var_temp;
}

/**
 * bhind_ndswap - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void bhind_ndswap(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *var_temp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = var_temp;
	else
		*tail = var_temp;
	var_temp->next = (*shaker)->next;
	(*shaker)->prev = var_temp->prev;
	if (var_temp->prev != NULL)
		var_temp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = var_temp;
	var_temp->prev = *shaker;
	*shaker = var_temp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (not_stirred == false)
	{
		not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				node_swap(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				bhind_ndswap(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				not_stirred = false;
			}
		}
	}
}
