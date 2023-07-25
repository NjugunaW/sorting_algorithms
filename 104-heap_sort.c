#include "sort.h"

void num_swap(int *first_num, int *second_num);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * num_swap - Swap two integers in an array.
 * @first_num: The first integer to swap.
 * @second_num: The second integer to swap.
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
 * max_heapify - function that maintains the max heap property of binary tree
 * @array: Array of ints.
 * @size: Size of array.
 * @base: Base index.
 * @root: Root node.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
/* Declaration of variables*/
	size_t left_side, right_side, large;
/* These lines of code calculate the indices of left and right sides of root*/
	left_side = 2 * root + 1;
	right_side = 2 * root + 2;
/* These lines of code determine the largest element among the 'root' */
	large = root;
/* If condtion to check whether left side is larger*/
	if (left_side < base && array[left_side] > array[large])
		large = left_side;
/* If conditio to check whether the right side is larger*/
	if (right_side < base && array[right_side] > array[large])
		large = right_side;
/* Function to check whether the largest element is not the current 'root'*/
	if (large != root)
	{
/* These ensure that the largest element is the current 'root'*/
		num_swap(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - function that sorts an array of integers in ascending order
 * @array: Array of ints.
 * @size: Size of array.
 *
 * Description: Implements the sift-down heap sort algorithm
 */
void heap_sort(int *array, size_t size)
{
/* Declaration of variables*/
	int i;
/* Condition to check if array is NULL or < 2*/
	if (array == NULL || size < 2)
		return; /* indicates there is nothign to sort*/
/* For loop to build a max heap from the input array*/
	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);
/* For loop to sort the array*/
	for (i = size - 1; i > 0; i--)
	{
		num_swap(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
