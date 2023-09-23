#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - Helper function to recursively perform Quick sort.
 * @array: The array to be sorted.
 * @low: The lowest index of the partition to be sorted.
 * @high: The highest index of the partition to be sorted.
 * @size: The size of the array (used for printing).
 */
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
	int pivot = lomuto_partition(array, low, high, size);

	quicksort(array, low, pivot - 1, size);
	quicksort(array, pivot + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort.
 * @array: The array to be sorted.
 * @low: The lowest index of the partition to be sorted.
 * @high: The highest index of the partition to be sorted.
 * @size: The size of the array (used for printing).
 * Return: The final pivot position.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
	if (array[j] < pivot)
	{
	i++;
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
	}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, size);

	return (i + 1);
}

