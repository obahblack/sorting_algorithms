#include "sort.h"
/**
 * shell_sort - sorts an array using shell sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	/* check if array is NULL or size is less than 2 */
	if (array == NULL || size < 2)
		return;

	/* determine gap sequence using knuth's formula */
	while (gap < size / 3)
		gap = (gap * 3) + 1;

	/* perform insertion sort on each gap */
	while (gap)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		print_array(array, size); /* print the array after each gap */
		gap /= 3; /* update the gap sequence */
	}
}
