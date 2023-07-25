#include "sort.h"

/**
 * num_swap - this function swaps two integers.
 * @a: First integer
 * @b: Second integer
 */
void num_swap(int *a, int *b)
{
/* Declaration of variables */
	int temporary_int;

/* This expression stores values */
	temporary_int = *a;
	*a = *b;
/* This line of code copies the value stored in the variable */
	*b = temporary_int;
}

/**
 * bubble_sort - function that sorts an array of integers in ascending order.
 * @array: pointer to the array
 * @size: size of array
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
/* Declaration of variables */
	size_t i, array_size = size;
	bool my_bubble = false;

/* This line of code checks if the array is NULL or < 2 */
	if (array == NULL || size < 2)
		return;
/* While loop to iterate over the array until no more swaps occur */
	while (my_bubble == false)
	{
		my_bubble = true; /*loop terminates if no swaps occur */
		for (i = 0; i < array_size - 1; i++)
		{
			if (array[i] > array[i + 1]) /* comparison of elements */
			{
/*This expression swaps the current element with the next element */
				num_swap(array + i, array + i + 1);
				print_array(array, size);
/*This function indicates that the array is not fully sorted */
				my_bubble = false;
			}
		}
		array_size--;
	}
}
