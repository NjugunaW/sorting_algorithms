#include "sort.h"

/**
 * num_swap - function that swaps two integers.
 * @first_num: First int
 * @second_num: Second int
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
 * selection_sort - function that sorts an array of integers in ascending order
 * @array: Array of ints.
 * @size: Size of array.
 *
 * Description: Print the array after each swap of elements
 */
void selection_sort(int *array, size_t size)
{
/* Declaration of variables*/
	int *minimum;
	size_t i, j;
/* This line checks if the array is NULL or < 2*/
	if (array == NULL || size < 2)
		return;
/* For loop to iterate over the array till the second last element*/
	for (i = 0; i < size - 1; i++)
	{
		minimum = array + i;
/* For loop to iterate over the array till the last element*/
		for (j = i + 1; j < size; j++)
/* Declared pointer 'minimum' is updated*/
			minimum = (array[j] < *minimum) ? (array + j) : minimum;
/* Once the smallest element is found,*/
/* Swap function is called*/
		if ((array + i) != minimum)
		{
			num_swap(array + i, minimum);
			print_array(array, size);
		}
	}
}
