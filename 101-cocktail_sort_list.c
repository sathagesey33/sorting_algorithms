#include "sort.h"
/**
 * get_elems - Counts the number of elements in a doubly linked list
 * @li: The double linked list to count
 * Return: Number of elements in the doubly linked list
 */
listint_t *get_elems(listint_t *li)
{
	listint_t *current = li;

	while (current->next != NULL)
	current = current->next;

	return (current);
}
/**
 * swap_nodes - Swap two nodes of a doubly linked list
 * @list: The double linked list that contains the nodes
 * @node: The node to swap with the next node
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;

	if (node->next->prev)
	node->prev->next = node->next;
	else
	*list = node->next;

	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;

	if (node->next)
	node->next->prev = node;
}
/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 * using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = INCREMENT;
	listint_t *current, *start = NULL, *end = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	start = current;
	end = get_elems(*list);

	while (start != end)
	{
		if (current->n == current->next->n)
			break;
		else if (current->n > current->next->n && swapped == INCREMENT)
			swap_nodes(list, current), print_list(*list);
		else if (current->next->n < current->n && swapped == DECREMENT)
			swap_nodes(list, current), current = current->prev, print_list(*list);
		else if (swapped == INCREMENT)
			current = current->next;
		else if (swapped == DECREMENT)
			current = current->prev;

		if (swapped == DECREMENT && current->next == start)
		{
			swapped = INCREMENT;
			current = current->next;
		}
		if (swapped == INCREMENT && current->prev == end)
		{
			end = end->prev;
			swapped = DECREMENT;
			current = current->prev;
		}
	}
}
