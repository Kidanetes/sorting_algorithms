#include "sort.h"
/**
 * cocktail_sort_list - sort a list
 * using cocktail sort aligorithm
 * @list: double linked list to be
 * sorted
 * Return: nothing
 */

void cocktail_sort_list(listint_t **list)
{
	int status = 1;
	listint_t *head, *tmp1, *tmp2, *tmp4;

	if (list == NULL || *list == NULL)
		return;

	head = *list;
	if (head->next == NULL)
		return;
	tmp1 = head;
	while (status != 0)
	{
		status = 0;
		while (tmp1->next != NULL)
		{
			if (tmp1->n > tmp1->next->n)
			{
				tmp2 = tmp1->next;
				if (tmp1->prev != NULL)
					tmp1->prev->next = tmp2;
				tmp4 = tmp2->next;
				if (tmp4 != NULL)
					tmp4->prev = tmp1;
				tmp2->next = tmp1;
				tmp2->prev = tmp1->prev;
				tmp1->next = tmp4;
				tmp1->prev = tmp2;
				status = 1;

				if (tmp1 == *list)
					*list = tmp2;
				print_list(*list);
				continue;
			}
			tmp1 = tmp1->next;
		}
		tmp1 =  tmp1->prev;
		if (status == 0)
			break;
		while (tmp1->prev != NULL)
                {
                        if (tmp1->n > tmp1->next->n)
                        {
                                tmp2 = tmp1->next;
                                if (tmp1->prev != NULL)
                                        tmp1->prev->next = tmp2;
                                tmp4 = tmp2->next;
                                if (tmp4 != NULL)
                                        tmp4->prev = tmp1;
                                tmp2->next = tmp1;
                                tmp2->prev = tmp1->prev;
                                tmp1->next = tmp4;
                                tmp1->prev = tmp2;
                                status = 1;

                                if (tmp1 == *list)
                                        *list = tmp2;
				print_list(*list);
				tmp1 = tmp2;
				continue;
                        }
                        tmp1 = tmp1->prev;
                }
	}
}
