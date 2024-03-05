#include "sort.h"

/**
 * bubble_sort - A function that sorts an array of integers in
 * ascending order using the bubble sort algorithm
 * @array: List of numbers to be sorted
 * @size: The size of the array
 *
 * Return: Each step of the sorted algorithm
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swapped;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}

		}

		if (swapped == 0)
			break;
	}
}
