#include "sort.h"

void num_swap(int *first_num, int *second_num);
int lomuto_partition(int *array, size_t size, int lower, int higher);
void lomuto_sort(int *array, size_t size, int lower, int higher);
void quick_sort(int *array, size_t size);

/**
 * num_swap - function that swaps two integers.
 * @first_num: Fisrt int
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
 * lomuto_partition - function used in quicksort to partition an array
 * @array: Array of ints
 * @size: Size of array
 * @lower: Subset of array to order
 * @higher: Subset of array to order
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int lower, int higher)
{
/* Declaration of variables*/
	int *pivot, above, below;
/* In this line of code, pivot is set to point to the element*/
/* In the 'array' at the 'higher' index*/
	pivot = array + higher;
/* For loop to iterate over the elements*/
	for (above = below = lower; below < higher; below++)
	{
/* Statement to check if element at current index is < 'pivot'*/
/* If above is true, the current element is moved to leftside of pivot*/
		if (array[below] < *pivot)
		{
			if (above < below)
			{
/* Swap function is called*/
				num_swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
/* Statement to check if element at current index is > 'pivot'*/
/* If above is true, the element is moved to correct postion in array*/
	if (array[above] > *pivot)
	{
/* Swap function is called*/
		num_swap(array + above, pivot);
		print_array(array, size);
	}
/* Funtion returns 'above' which reps the final partition index*/
	return (above);
}

/**
 * lomuto_sort - function that implements quicksort algorithm.
 * @array: Array of ints
 * @size: Size of array
 * @lower: Subset of array to order
 * @higher: Subset of array to order
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int lower, int higher)
{
/* Declaration of variables*/
	int partition;
/* If statement to check if partition is > '0'*/
	if (higher - lower > 0)
	{
/* If above statement is true, the function sorts the array*/
		partition = lomuto_partition(array, size, lower, higher);
/* Function calls itself recursively*/
		lomuto_sort(array, size, lower, partition - 1);
		lomuto_sort(array, size, partition + 1, higher);
	}
}

/**
 * quick_sort - function that sorts an array of integers in ascending order
 * @array: Array of ints
 * @size: Size of array
 *
 * Description: Implement the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
/* Condition to check if 'array' is NULL or < 2*/
	if (array == NULL || size < 2)
		return; /*means theres is nothing to sort*/
/* Function to initiate quicksort is called*/
	lomuto_sort(array, size, 0, size - 1);
}
