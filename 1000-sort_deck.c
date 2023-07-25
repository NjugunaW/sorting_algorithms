#include "deck.h"

int _strcmp(const char *first_string, const char *second_string);
char get_value(deck_node_t *card);
void insertion_sort_per_suit(deck_node_t **deck);
void insertion_sort_card_values(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - This function compares 2 strings
 * @first_string: The original string
 * @second_string: The comparative string.
 *
 * Return: Positive byte difference if first_string > second_string
 *         Negative byte difference if first_string < second_string
 *         0 by default
 */
int _strcmp(const char *first_string, const char *second_string)
{	/*This loop keeps the function running as long as there is a string*/
	while (*first_string && *second_string && *first_string == *second_string)
	{
		first_string++;
		second_string++;
	}
	/*This statement returns the byte on difference*/
	if (*first_string != *second_string)
		return (*first_string - *second_string);
	/*Default return value*/
	return (0);
}

/**
 * get_value - This function gets the numerical value of
 * a card
 * @card: A pointer to the card.
 *
 * Return: The numerical value of the card.
 */
char get_value(deck_node_t *card)
{
		/*This group of if statements check and return the*/
		/*value of the card*/
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_per_suit - This function sorts the deck per suite
 * from Spades to Diamonds.
 * @deck: A pointer to the head of a deck.
 */
void insertion_sort_per_suit(deck_node_t **deck)
	/*Variable Declaration*/
{
	deck_node_t *iter, *insert, *temporary_node;

	for (iter = (*deck)->next; iter != NULL; iter = temporary_node)
	{
		temporary_node = iter->next;
		insert = iter->prev;
		while (insert != NULL && insert->card->kind > iter->card->kind)
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * insertion_sort_card_values - Sorts the cards from Ace to King
 * @deck: A pointer to the head of a deck node.
 */
void insertion_sort_card_values(deck_node_t **deck)
{
	/*Declaring variables*/
	deck_node_t *iter, *insert, *temporary_node;

	for (iter = (*deck)->next; iter != NULL; iter = temporary_node)
	{
		temporary_node = iter->next;
		insert = iter->prev;
		while (insert != NULL && insert->card->kind ==
		iter->card->kind && get_value(insert) > get_value(iter))
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * sort_deck -This function sorts a deck of cards from ace of spades to
 * king of Diamonds
 * @deck: A pointer to the head of a deck.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_per_suit(deck);
	insertion_sort_card_values(deck);
}
