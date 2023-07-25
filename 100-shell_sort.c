#include "sort.h"

/**
 * num_swap - function that swaps two integers.
 * @first_num: Fisrt int
 * @second_num: Fisrt int
 */
void num_swap(int *first_num, int *second_num)
{
/* Declaration of variables*/
	int temporary_num;
/* The value of first int is stored in the declared variable*/
	temporary_num = *first_num;
/* The value of the second int is assigned to the frist int*/
	*first_num = *second_num;
/* The value of the variable is stored in the second int*/
	*second_num = temporary_num;
}

/**
 * shell_sort - function that sorts an array of integers in ascending order
 * @array: Array of ints
 * @size: Size of array
 *
 * Description: Prints array each time the interval decreases
 */
void shell_sort(int *array, size_t size)
{
/* Declaration of variables*/
	size_t rng, i, j;
/* Condition to check if 'array' is NULL or < 2*/
	if (array == NULL || size < 2)
		return; /* means there is nothing to sort*/
/* For loop to initialize 'rng' var to the fisrt gap size*/
	for (rng = 1; rng < (size / 3);)
		rng = rng * 3 + 1; /*'rng starts at '1' then set to 'rng * 3 + 1'*/
/* Loop to run with the decreasing gap size starting from the largest gap*/
	for (; rng >= 1; rng /= 3)
	{
/* Inner loop to initialize 'i' to 'rng'*/
/* This shows the starting index for the sub-array*/
		for (i = rng; i < size; i++)
		{
			j = i;
/* While loop to run as long as there are elements in the sub-array*/
			while (j >= rng && array[j - rng] > array[j])
			{
				num_swap(array + j, array + (j - rng));
				j -= rng;
			}
		}
		print_array(array, size);
	}
}
