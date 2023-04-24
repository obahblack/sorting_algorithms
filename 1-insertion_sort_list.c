#include "sort.h"
/**
 * insertion_sort_list - inserts right unsorted side into left sorted side
 * @list: doubly linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, *temp, *prev;

	while (current != NULL)
	{
		temp = current;
		prev = current->prev;
		while (prev != NULL && prev->n > temp->n)
		{
			if (temp->next != NULL)
				temp->next->prev = prev;
			prev->next = temp->next;
			temp->prev = prev->prev;

			if (prev->prev != NULL)
				prev->prev->next = temp;

			else
				*list = temp;
			temp->next = prev;
			prev->prev = temp;
			print_list(*list);
			prev = temp->prev;
		}
		current = current->next;
	}
}
