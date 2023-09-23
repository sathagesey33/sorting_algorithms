#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using Insertion sort.
 * @list: A pointer to a pointer to the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL)
	return;

	current = (*list)->next;
	while (current != NULL)
	{
	temp = current;
	prev = current->prev;

	while (prev != NULL && prev->n > temp->n)
	{
	if (temp->next != NULL)
	temp->next->prev = prev;
	prev->next = temp->next;
	temp->prev = prev->prev;
	temp->next = prev;

	if (prev->prev != NULL)
	prev->prev->next = temp;
	prev->prev = temp;

	if (prev == *list)
	*list = temp;

	print_list(*list);
	prev = temp->prev;
	}
	current = current->next;
	}
}

