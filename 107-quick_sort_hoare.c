#include "sort.h"

void num_swap(int *first_num, int *second_num);
int hoare_partition(int *array, size_t size, int lower, int higher);
void hoare_sort(int *array, size_t size, int lower, int higher);
void quick_sort_hoare(int *array, size_t size);

/**
 * num_swap - Swap two integers in an array.
 * @first_num: The first integer to swap.
 * @second_num: The second integer to swap.
 */
void num_swap(int *first_num, int *second_num)
{
	int temporary_num;

	temporary_num = *first_num;
	*first_num = *second_num;
	*second_num = temporary_num;
}

/**
 * hoare_partition - function that orders a subset of an array of integers.
 * @array: The array of integers.
 * @size: The size of the array.
 * @lower: The starting index of the subset to order.
 * @higher: The ending index of the subset to order.
 * Return: The final partition index.
 */
int hoare_partition(int *array, size_t size, int lower, int higher)
{
	/*Declaring variables*/
	int pivot, above, below;

	pivot = array[higher];
	for (above = lower - 1, below = higher + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			num_swap(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @lower: The starting index of the array partition to order.
 * @higher: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int lower, int higher)
{
	/*Declaring variables*/
	int partition;

	if (higher - lower > 0)
	{
		partition = hoare_partition(array, size, lower, higher);
		hoare_sort(array, size, lower, partition - 1);
		hoare_sort(array, size, partition, higher);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
