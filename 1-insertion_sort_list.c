#include "sort.h"
#include <stdlib.h>

/**
 * insertion_sort_list - sort a list using
 * insertion sort aligorithm
 * @list: double linked list
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head;
	listint_t *tmp1, *tmp2, *tmp3, *tmp4;

	if (list == NULL || *list == NULL)
		return;
	head = *list;
	if (head->next == NULL)
		return;
	tmp3 = head->next;

	while (tmp3 != NULL)
	{
		tmp2 = tmp3;
		while (tmp2->prev != NULL)
		{
			if ((tmp2->n)  < (tmp2->prev->n))
			{
				tmp1 = tmp2->prev;
				if (tmp1->prev != NULL)
					tmp1->prev->next = tmp2;
				tmp4 = tmp2->next;
				if (tmp4 != NULL)
					tmp4->prev = tmp1;
				tmp2->next = tmp1;
				tmp2->prev = tmp1->prev;
				tmp1->next = tmp4;
				tmp1->prev = tmp2;

				if (tmp1 == *list)
					*list = tmp2;
				print_list(*list);
				continue;
			}
			tmp2 = tmp2->prev;
		}
		tmp3 = tmp3->next;
	}
}
