#include "sort.h"

void num_swap(int *first_num, int *second_num);
void bitonic_merge(int *array, size_t size, size_t start, size_t sequence,
		char direc);
void bitonic_sequence(int *array, size_t size, size_t start,
			size_t sequence, char direc);
void bitonic_sort(int *array, size_t size);

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
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @sequence: The size of the sequence to sort.
 * @direc: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t sequence,
		char direc)
{
	/*Declaring variables*/
	size_t i, step = sequence / 2;

	if (sequence > 1)
	{
		for (i = start; i < start + step; i++)
		{
			if ((direc == UP && array[i] > array[i + step]) ||
			    (direc == DOWN && array[i] < array[i + step]))
				num_swap(array + i, array + i + step);
		}
		bitonic_merge(array, size, start, step, direc);
		bitonic_merge(array, size, start + step, step, direc);
	}
}

/**
 * bitonic_sequence - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @sequence: The size of a block of the building bitonic sequence.
 * @direc: The direction to sort the bitonic sequence block in.
 */
void bitonic_sequence(int *array, size_t size, size_t start,
			size_t sequence, char direc)
{
	/*Declaring variables*/
	size_t cut = sequence / 2;
	char *str = (direc == UP) ? "UP" : "DOWN";

	if (sequence > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sequence, size, str);
		print_array(array + start, sequence);

		bitonic_sequence(array, size, start, cut, UP);
		bitonic_sequence(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, sequence, direc);

		printf("Result [%lu/%lu] (%s):\n", sequence, size, str);
		print_array(array + start, sequence);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, size, 0, size, UP);
}
