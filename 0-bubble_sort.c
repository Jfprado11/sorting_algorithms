#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @size: size of the array
 * @array: array to be sorted
 * Return: a pointer to the newly created hash table.
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j = 1;
	int temp = 0;

	if (size >= 2)
	{
	while (j > 0)
	{
		j = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
				j++;
			}
		}
	}
	}
}
