#include "sort.h"

/**
 * find_highest - function that gets the maximum value in an array of ints.
 * @array: Array of ints.
 * @size: Size of array.
 *
 * Return: The maximum integer in the array.
 */
int find_highest(int *array, int size)
{
/* Declaration of variables*/
	int highest_num, i;
/* Loop to iterate over the array starting from the second element*/
	for (highest_num = array[0], i = 1; i < size; i++)
	{
		if (array[i] > highest_num)
			highest_num = array[i];
	}

	return (highest_num); /*reps the maximum int in array*/
}

/**
 * counting_sort - function that sorts an array in ascending order
 * @array: Array of ints
 * @size: Size of array
 *
 * Description: Prints the counting array
 */
void counting_sort(int *array, size_t size)
{
/* Declaration of variables*/
	int *count, *sorted, highest_num, i;
/* Condition tocheck if array is NULL or < 2*/
	if (array == NULL || size < 2)
		return; /*indicates array is empty*/
/* Dynamic mem allocation is performed to the 'sorted'array*/
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	highest_num = find_highest(array, size);
/* Memory allocation in heap*/
	count = malloc(sizeof(int) * (highest_num + 1));
/* Condition to see if malloc was successful or not*/
	if (count == NULL)
	{
		free(sorted);
		return;
	}
/* For loop is initialised*/
	for (i = 0; i < (highest_num + 1); i++)
		count[i] = 0;
/* For loop to iterate over elements in array*/
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
/* For loop that updates the 'count' array*/
	for (i = 0; i < (highest_num + 1); i++)
		count[i] += count[i - 1];
	print_array(count, highest_num + 1);
/* A loop to perform the sorting. It iterates over the 'array'*/
/* And updates 'count' array*/
	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];
	free(sorted);
	free(count);
}
