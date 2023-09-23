#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using Insertion sort.
 * @list: A pointer to a pointer to the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *transit;

	if (list == NULL || *list == NULL)
	return;

	current = (*list)->next;
	while (current != NULL)
	{
	transit = current;
	prev = current->prev;

	while (prev != NULL && prev->n > transit->n)
	{
	if (transit->next != NULL)
	transit->next->prev = prev;
	prev->next = transit->next;
	transit->prev = prev->prev;
	transit->next = prev;

	if (prev->prev != NULL)
	prev->prev->next = transit;
	prev->prev = transit;

	if (prev == *list)
	*list = transit;

	print_list(*list);
	prev = transit->prev;
	}
	current = current->next;
	}
}

