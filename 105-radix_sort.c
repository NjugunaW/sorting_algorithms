#include "sort.h"

int find_highest(int *array, int size);
void radix_counting_sort(int *array, size_t size, int signif_digit, int *buffer);
void radix_sort(int *array, size_t size);

/**
 * find_highest - This function finds the highest valie number in the array
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Return: The highest integer in the array.
 */
int find_highest(int *array, int size)
{
	/*Declaring the variables*/
	int highest, i;
	/*This for loop loops through the array to get*/
	/*the highest integer*/
	for (highest = array[0], i = 1; i < size; i++)
	{
		if (array[i] > highest)
			highest = array[i];
	}

	return (highest);
}

/**
 * radix_counting_sort - This function sorts the significant digits of an array
 * of integers in ascending order using the counting sort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 * @signif_digit: The significant digit to sort on.
 * @buffer: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int signif_digit, int *buffer)
{
	/*Declaring variables*/
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / signif_digit) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buffer[count[(array[i] / signif_digit) % 10] - 1] = array[i];
		count[(array[i] / signif_digit) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buffer[i];
}

/**
 * radix_sort - This function sorts an array of integers in ascending order
 * using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	/*Declaring Variables*/
	int highest, signif_digit, *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	highest = find_highest(array, size);
	for (signif_digit = 1; highest / signif_digit > 0; signif_digit *= 10)
	{
		radix_counting_sort(array, size, signif_digit, buffer);
		print_array(array, size);
	}

	free(buffer);
}
