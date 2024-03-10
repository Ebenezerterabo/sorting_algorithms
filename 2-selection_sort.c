#include "sort.h"

/**
 * selection_sort - A function that sorts an array of integers in ascending
 * order using the selection sort algorithm
 * @array: The list of element
 * @size: The size of the array
 *
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	/* iterate through the entire array */
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		/* Find the index of the minimum element int eh remaining unsorted part */
		for (j = i + 1; j < size; j++)
		{
			/* if we find a smaller element, update the minimum index */
			if (array[j] < array[min])
				min = j;
		}

		/* swap the current element with the minimum element */
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}


	}
}
