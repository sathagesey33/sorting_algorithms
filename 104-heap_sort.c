#include "sort.h"

/**
 * swap_heap - Swaps two integers in an array and prints the array.
 * @array: The array of integers.
 * @size: The size of the array.
 * @a: Index of the first integer to swap.
 * @b: Index of the second integer to swap.
 */
void swap_heap(int *array, size_t size, int a, int b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;

	print_array(array, size);
}

/**
 * sift_down - Sifts down value in heap to maintain the max-heap property.
 * @array: The array representing the heap.
 * @size: The size of the heap.
 * @root: The root of the subtree to sift down.
 * @max_size: The maximum size of the heap.
 */
void sift_down(int *array, size_t size, size_t root, size_t max_size)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < max_size && array[left] > array[largest])
	largest = left;

	if (right < max_size && array[right] > array[largest])
	largest = right;

	if (largest != root)
	{
	swap_heap(array, size, root, largest);
	sift_down(array, size, largest, max_size);
	}
}

/**
 * heapify - Builds a max-heap from an array.
 * @array: The array to build the heap from.
 * @size: The size of the array.
 */
void heapify(int *array, size_t size)
{
	int i;

	for (i = (size / 2) - 1; i >= 0; i--)
	sift_down(array, size, i, size);
}

/**
 * heap_sort - Sorts an array of integers in ascending order using heap sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
	return;

	heapify(array, size);

	for (i = size - 1; i > 0; i--)
	{
	swap_heap(array, size, 0, i);
	sift_down(array, size, 0, i);
	}
}
