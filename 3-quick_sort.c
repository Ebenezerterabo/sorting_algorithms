#include "sort.h"

/**
 * quick_sort - A function that sorts an array of integers in ascending order
 * using the quick sort algorithm
 * @array: The list of element
 * @size: Size of the array
 *
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	sorted_array(array, 0, size - 1, size);
}

/**
 * sorted_array - sorts an array of integers using lomuto partition scheme
 * @array: The list of element
 * @low: The lowest index of the array
 * @high: The highest index of the array
 * @size: Size of the array
 *
 * Return: Nothing
 */

void sorted_array(int *array, int low, int high, size_t size)
{
	int part_stored;

	if (low < high)
	{
		part_stored = partition_func(array, low, high, size);
		sorted_array(array, low, part_stored - 1, size);
		sorted_array(array, part_stored + 1, high, size);
	}
}

/**
 * partition_func - Divide array into two parts
 * @array: The array to be divided
 * @low: The lowest index of the array
 * @high: The highest index of the array
 * @size: The size of the array
 *
 * Return: The pivot after dividing the array
 */

int partition_func(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i, j = low - 1, temp;

	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			j++;
			if (j != i)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	}

	if ((j + 1) != high)
	{
		temp = array[j + 1];
		array[j + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (j + 1);
}
