#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: array to be sorted
 * @size: array size
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, position, temp;

	if (size >= 2)
	{
		for (i = 0; i < size - 1; i++)
		{
			position = i;

			for (j = i + 1; j < size; j++)
			{
				if (array[position] > array[j])
					position = j;
			}
			if (position != i)
			{
				temp = array[i];
				array[i] = array[position];
				array[position] = temp;
				print_array(array, size);
			}
		}
	}
}
