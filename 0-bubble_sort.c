#include "sort.h"

/**
* bubble_sort - swapps a list of array using bubble sort method.
* @array: array to be sorted.
* @size: size of array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, kev;
	int tempy;
	int swappy;
	
	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
	swappy = 0;

	for (kev = 0; kev < size - i - 1; kev++)
	{
	if (array[kev] > array[kev + 1])
	{
	tempy = array[kev];
	array[kev] = array[kev + 1];
	array[kev + 1] = tempy;

	swappy = 1;
	print_array(array, size);
	}
	}

	if (swappy == 0)
	break;
	}
}
