#include "sort.h"

void swap_prior_node(listint_t **list, listint_t **tail,
			listint_t **cocktail_shaker);
void swap_post_node(listint_t **list, listint_t **tail,
			listint_t **cocktail_shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_prior_node - functtion that swaps a node in a doubly linked list
 * @list: double pointer to a struct
 * @tail: double pointer to a struct
 * @cocktail_shaker: double pointer to a struct
 */
void swap_prior_node(listint_t **list, listint_t **tail,
			listint_t **cocktail_shaker)
{
/* Declaring the variable and initializing it to the next node */
	listint_t *temporary = (*cocktail_shaker)->next;
/* Condition to check if there is a previous node*/
/* These lines of code also handle the update of the 'next' pointer*/
	if ((*cocktail_shaker)->prev != NULL)
		(*cocktail_shaker)->prev->next = temporary;
	else
/* If 'cocktail_shaker' is the head of the list, then it is swapped*/
		*list = temporary;
/* This line updates the 'prev' pointer of 'temporary' to point to the */
/* previous node of the *'cocktail_shaker'*/
	temporary->prev = (*cocktail_shaker)->prev;
	(*cocktail_shaker)->next = temporary->next;
/* Condition to check if there is a next node*/
	if (temporary->next != NULL)
		temporary->next->prev = *cocktail_shaker;
	else
		*tail = *cocktail_shaker;
/* 'prev' pointer of '*cocktail_shaker' is updated to point to */
/* 'temporary' and the 'next' pointer of 'temporary' to point to */
/* ,*cocktail_shaker'*/
	(*cocktail_shaker)->prev = temporary;
	temporary->next = *cocktail_shaker;
	*cocktail_shaker = temporary;
}

/**
 * swap_post_node - this function swaps nodes in a doubly-linked list
 * @list: double pointer to a struct
 * @tail: double pointer to a struct
 * @cocktail_shaker: double pointer to a struct
 */
void swap_post_node(listint_t **list, listint_t **tail,
			listint_t **cocktail_shaker)
{
/* Declaration of temporary pointers*/
	listint_t *temporary = (*cocktail_shaker)->prev;
/* If condition to check whether '*cocktail_shaker' has a next node*/
/* If above is true, 'prev' pointer is updated to point to 'temporary' node*/
	if ((*cocktail_shaker)->next != NULL)
		(*cocktail_shaker)->next->prev = temporary;
/* If above condition is not true, the 'tail' pointer is updated to point to*/
/* the 'temporary' node*/
	else
		*tail = temporary;
	temporary->next = (*cocktail_shaker)->next; /*updating the node*/
/* This line of code ensures 'cocktail_shaker is the node behind 'temporary'*/
	(*cocktail_shaker)->prev = temporary->prev;
/* Condition to check if 'temporary' node has a previous node*/
/* If so, 'next' pointer of previous node is updated*/
	if (temporary->prev != NULL)
		temporary->prev->next = *cocktail_shaker;
	else
		*list = *cocktail_shaker;
	(*cocktail_shaker)->next = temporary; /* completion of swap*/
	temporary->prev = *cocktail_shaker;
	*cocktail_shaker = temporary;
}

/**
 * cocktail_sort_list - this function sorts a doubly linked list
 * @list: double pointer to a struct
 */
void cocktail_sort_list(listint_t **list)
{
/* Declaration of variables*/
	listint_t *tail, *cocktail_shaker;
	bool james_bond = false; /* boolean variable to flag any swaps*/
/* Condition to check if list is empty or only contains one element*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
/* Loop that finds last node of list and assigns it to the 'tail' pointer*/
	for (tail = *list; tail->next != NULL;)
		tail = tail->next;
/* While loop that will run until no swaps are made during iteration*/
	while (james_bond == false)
	{
		james_bond = true;
		for (cocktail_shaker = *list; cocktail_shaker != tail;
				cocktail_shaker = cocktail_shaker->next)
		{
			if (cocktail_shaker->n > cocktail_shaker->next->n)
			{
				swap_prior_node(list, &tail, &cocktail_shaker);
				print_list((const listint_t *)*list);
				james_bond = false;
			}
		}
/* Loop that reps the forward pass of the cocktail shaker algorithm*/
		for (cocktail_shaker = cocktail_shaker->prev; cocktail_shaker != *list;
				cocktail_shaker = cocktail_shaker->prev)
		{
			if (cocktail_shaker->n < cocktail_shaker->prev->n)
			{
				swap_post_node(list, &tail, &cocktail_shaker);
				print_list((const listint_t *)*list);
				james_bond = false;
			}
		}
	}
}
