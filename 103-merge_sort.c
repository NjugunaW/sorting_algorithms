#include "sort.h"

void sub_sort(int *sub_array, int *sub_buffer, size_t front, size_t mid,
		size_t back);
void merge_sort_recursion(int *sub_array, int *sub_buffer,
		size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * sub_sort - function that sorts a subarray of ints.
 * @sub_array: A subarray of an array of ints
 * @sub_buffer: A buffer to store the sorted subarray.
 * @front: Index of array.
 * @mid: Index of array.
 * @back: Index of array.
 */
void sub_sort(int *sub_array, int *sub_buffer, size_t front, size_t mid,
		size_t back)
{
/* Declaration of variables*/
	size_t a, b, c = 0;
/* These lines of code print the info about subarray before sorting*/
	printf("Merging...\n[left]: ");
	print_array(sub_array + front, mid - front);

	printf("[right]: ");
	print_array(sub_array + mid, back - mid);
/* For loop to sort the the two halves of subarray*/
	for (a = front, b = mid; a < mid && b < back; c++)
		sub_buffer[c] = (sub_array[a] < sub_array[b])
		? sub_array[a++] : sub_array[b++];
/* For loop to handle rem elements in the left subarray*/
	for (; a < mid; a++)
		sub_buffer[c++] = sub_array[a];
/* For loop to handle rem elements in the right subarray*/
	for (; b < back; b++)
		sub_buffer[c++] = sub_array[b];
/* This for loop copies the sorted elements and*/
/* arranges them in ascending order*/
	for (a = front, c = 0; a < back; a++)
		sub_array[a] = sub_buffer[c++];
/* These lines print info about the subarray after sorting*/
	printf("[Done]: ");
	print_array(sub_array + front, back - front);
}

/**
 * merge_sort_recursion - Implement the merge sort algorithm through recursion.
 * @sub_array: A subarray of an array of integers to sort.
 * @sub_buffer: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursion(int *sub_array, int *sub_buffer,
			size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursion(sub_array, sub_buffer, front, mid);
		merge_sort_recursion(sub_array, sub_buffer, mid, back);
		sub_sort(sub_array, sub_buffer, front, mid, back);
	}
}

/**
 * merge_sort - function that sorts an array of integers in ascending order
 * @array: Array of ints.
 * @size: Size of array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
/* Declaration of variables*/
	int *sub_buffer;
/* Condition to check if array is NULL or < 2*/
	if (array == NULL || size < 2)
		return; /*indicates there is nothing to sort*/
/* Mem allocation for 'sub_buffer' which will be used temporarily*/
	sub_buffer = malloc(sizeof(int) * size);
/* Condition to check whether malloc was successful or not*/
	if (sub_buffer == NULL)
		return;
/* Function to perform top-down recursive merge sort on the array*/
	merge_sort_recursion(array, sub_buffer, 0, size);
/* Mme allocated for 'sub_buffer' is freed after sorting is done*/
	free(sub_buffer);
}
