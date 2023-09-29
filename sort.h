#ifndef SORT_H
#define SORT_H

#define INCREMENT 1
#define DECREMENT -1

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* print prototypes */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/* custom function prototypes */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
listint_t *create_listint(const int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
listint_t *get_elems(listint_t *li);
void swap_nodes(listint_t **list, listint_t *node);
void counting_sort(int *array, size_t size);
void merge(int *array, int *left, size_t left_size,
		int *right, size_t right_size);
void merge_sort(int *array, size_t size);
void sift_down(int *array, size_t size, size_t root, size_t max_size);
void heapify(int *array, size_t size);
void heap_sort(int *array, size_t size);
/* helper function */
void swap(int *a, int *b);
void quicksort(int *array, int low, int high, size_t size);
void swap_heap(int *array, size_t size, int a, int b);
#endif
