#include "sort.h"

/**
 * merge - Merges two subarrays of the original array.
 * @array: The original array.
 * @left: Pointer to the left subarray.
 * @left_size: Size of the left subarray.
 * @right: Pointer to the right subarray.
 * @right_size: Size of the right subarray.
 */
void merge(int *array, int *left, size_t left_size,
		int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *merged_array;

	merged_array = malloc((left_size + right_size) * sizeof(int));

	if (!merged_array)
	return;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
	if (left[i] <= right[j])
	merged_array[k++] = left[i++];
	else
	merged_array[k++] = right[j++];
	}

	while (i < left_size)
	merged_array[k++] = left[i++];

	while (j < right_size)
	merged_array[k++] = right[j++];

	for (i = 0; i < left_size + right_size; i++)
	array[i] = merged_array[i];

	free(merged_array);

	printf("[Done]: ");
	print_array(array, left_size + right_size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t middle = size / 2;
	int *left = array;
	int *right = array + middle;
	size_t left_size = middle;
	size_t right_size = size - middle;

	if (size < 2 || !array)
	return;

	merge_sort(left, left_size);
	merge_sort(right, right_size);

	merge(array, left, left_size, right, right_size);
}
