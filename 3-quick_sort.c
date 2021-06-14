#include "sort.h"

/**
 *quick_sort - sorted an array if the size is grater than two
 *@array: the array to be sorted
 *@size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	int high, low;

	low = 0;
	high = size - 1;
	if (size >= 2)
	{
		qs(array, low, high, size);
	}
}

/**
 * qs - does the recursion and partion of the array
 *@array: the array to be parted
 * @low: the lowest int
 *@high: the highest int
 *@size: the size of the array
 */
void qs(int *array, int low, int high, size_t size)
{
	int pi = 0;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		qs(array, low, pi - 1, size);
		qs(array, pi + 1, high, size);
	}
}
/**
 *partition - the partition of the array
 *@array: the array to be parted
 *@low: the lowest int
 *@high: the highest int
 *@size: the size of the array
 *Return: the i value
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low, j = 0, temp;

	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
		}
	}
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;
	print_array(array, size);
	return (i);
}
