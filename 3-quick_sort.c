#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partitions the array using Lomuto partition scheme
 * @array: The array to be partitioned
 * @low: The low index of the current partition
 * @high: The high index of the current partition
 * @size: The size of the array
 *
 * Return: The index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
	if (array[j] < pivot)
	{
	i++;
	swap(&array[i], &array[j]);
	if (i != j)
	{
	print_array(array, size);
	}
	}
	}
	swap(&array[i + 1], &array[high]);
	if (i + 1 != high)
	{
	print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Recursive function to perform quick sort
 * @array: The array to be sorted
 * @low: The low index of the current partition
 * @high: The high index of the current partition
 * @size: The size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
	int pi = lomuto_partition(array, low, high, size);

	quicksort(array, low, pi - 1, size);
	quicksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	quicksort(array, 0, size - 1, size);
}
