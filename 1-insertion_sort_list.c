#include "sort.h"

/**
 * node_swap - this function swaps nodes.
 * @list_head: double pointer to a struct
 * @first_node: double pointer to a struct
 * @second_node: pointer to a struct
 */
void node_swap(listint_t **list_head,
			listint_t **first_node, listint_t *second_node)
{
/*This line of code updates a pointer to point to the next node */
	(*first_node)->next = second_node->next;
/*These lines of code ensure that the linked list remains intact */
/*After the swap*/
	if (second_node->next != NULL)
		second_node->next->prev = *first_node;
/*This expression updates previous pointer to point to node before*/
	second_node->prev = (*first_node)->prev;
	second_node->next = *first_node;
	if ((*first_node)->prev != NULL)
		(*first_node)->prev->next = second_node;
/* This code updates the header pointer */
	else
		*list_head = second_node;
	(*first_node)->prev = second_node;
	*first_node = second_node->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of ints in ascending order
 * @list: a double poiter to a struct
 *
 * Description: prints list after swapping elements.
 */
void insertion_sort_list(listint_t **list)
{
/* Declaration of pointers */
/* These pointers will be used to as iterators whiles sorting*/
	listint_t *iterable, *insert, *temporary;
/* This line of code checks if *list is NULL and elements in it*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
/* For loop to iterate over the list as long as it is not empty*/
	for (iterable = (*list)->next; iterable != NULL; iterable = temporary)
	{
/* Assigning of values and pointers*/
		temporary = iterable->next;
		insert = iterable->prev;
/* While loop to sort using insertion algorithm*/
		while (insert != NULL && iterable->n < insert->n)
		{
			node_swap(list, &insert, iterable);
			print_list((const listint_t *)*list);
		}
	}
}
