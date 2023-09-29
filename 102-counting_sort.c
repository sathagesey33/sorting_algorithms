#include "sort.h"

/**
 * counting_sort - sort array with counting method
 * @array: array to sort
 * @size: size of array
 *
 * Return: nothing
*/

void counting_sort(int *max, size_t I)
{
	int max_val = 0, I_val = 1;
	int *counting_array = NULL, *sorted_index = NULL;

	if (!max || I < 2)
		return;
	max_val = max[0];
	while (I_val < (int) I)
	{
		if (max[I_val] > max_val)
			max_val = max[I_val];
		I_val++;
	}
	sorted_index = malloc(sizeof(int) * I);
	if (!sorted_index)
		return;
	counting_array = malloc(sizeof(int) * max_val + 1);
	if (!counting_array)
	{
		free(sorted_index);
		return;
	}

	for (I_val = 0; I_val <= max_val; ++I_val)
		counting_array[I_val] = 0;
	for (I_val = 0; I_val < (int) I; ++I_val)
		counting_array[max[I_val]]++;
	for (I_val = 1; I_val <= max_val; ++I_val)
		counting_array[I_val] = counting_array[I_val - 1] + counting_array[I_val];
	print_array(counting_array, max_val + 1);
	for (I_val = 0; I_val < (int) I; ++I_val)
	{
		sorted_index[counting_array[max[I_val]] - 1] = max[I_val];
		counting_array[max[I_val]]--;
	}
	for (I_val = 0; I_val < (int) I; ++I_val)
		max[I_val] = sorted_index[I_val];

	free(counting_array);
	free(sorted_index);
	counting_array = sorted_index = NULL;
}
