#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: head pointer to list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *temp = NULL;

	temp = *list;
	while (temp->next != NULL)
	{
		current = temp->next;
		while (current != NULL)
		{
			if (temp->n > current->n)
			{
				_swap(&temp, &current, &(*list));
				print_list(*list);
			}
			current = current->next;
		}
		temp = temp->next;
	}
}

/**
 * _swap - swap two nodes
 * @temp: temporal pointer to node
 * @current: temporal pointer to node
 * @list: head pointer to list
 * Return: nothing
 */
void _swap(listint_t **temp, listint_t **current, listint_t **list)
{
	if ((*temp)->prev != NULL)
	{
		(*current)->prev->next = (*current)->next;
		if ((*current)->next != NULL)
		{
			(*current)->next->prev = (*current)->prev;
		}
		(*current)->prev = NULL;
		(*current)->next = NULL;
		(*current)->prev = (*temp)->prev;
		(*current)->next = *temp;
		(*temp)->prev = *current;
		(*current)->prev->next  = *current;
		*temp = *current;
	}
	else
	{
		(*current)->prev->next = (*current)->next;
		if ((*current)->next != NULL)
		{
			(*current)->next->prev = (*current)->prev;
		}
		(*current)->next = NULL;
		(*current)->prev = NULL;
		(*current)->next = *temp;
		(*temp)->prev = *current;
		*list = *current;
		*temp = *current;
	}
}
