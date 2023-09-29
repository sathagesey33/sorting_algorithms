#include "sort.h"

/**
 * getMax - Get the maximum value from an array.
 * @array: The array to search for the maximum value.
 * @size: The size of the array.
 * Return: The maximum value in the array.
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
	if (array[i] > max)
	max = array[i];
	}
	return (max);
}

/**
 * countingSort - Perform counting sort on the array.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @exp: The current exponent (1 for LSD).
 */
void countingSort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (!output)
	return;

	for (i = 0; i < size; i++)
	count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
	count[i] += count[i - 1];

	for (i = size - 1; i < size; i--)
	{
	output[count[(array[i] / exp) % 10] - 1] = array[i];
	count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
	array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using radix sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max = getMax(array, size);
	int exp;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
	countingSort(array, size, exp);
	print_array(array, size);
	}
}
