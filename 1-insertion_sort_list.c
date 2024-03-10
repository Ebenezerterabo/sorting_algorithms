#include "sort.h"

/**
 * insertion_sort_list - A function that sorts a doubly linked list of integers
 * in ascending order using insertion sort algorithm
 * @list: Doubly linked list
 *
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;
	listint_t *temp, *insertion_point;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return; /* skip empty lists or one-element lsits */

	/* Traverse through the entire list */
	while (current != NULL)
	{
		insertion_point = current->prev; /* start from the node before current*/
		while (insertion_point != NULL && insertion_point->n > current->n)
		{
			/* Swap the current node with the node before it */
			temp = insertion_point->prev;
			insertion_point->prev = current->prev;
			current->prev = temp;

			if (temp != NULL)
				temp->next = current;
			else
				*list = current;

			insertion_point->next = current->next;
			if (current->next != NULL)
				current->next->prev = insertion_point;

			current->next = insertion_point;
			insertion_point->prev = current;

			print_list(*list);

			insertion_point = current->prev; /* move insertion point back */
		}
		current = current->next;
	}
}
