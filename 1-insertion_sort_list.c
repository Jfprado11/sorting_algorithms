#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: head pointer to list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *sorted = NULL, *next = NULL;

	if (*list == NULL || (*list)->next == NULL)
	{
		return;
	}

	sorted = (*list)->next;
	current = *list;
	next = sorted;
	while (next != NULL)
	{
		sorted = next;
		current = sorted->prev;
		while (sorted->prev != NULL && sorted->n < current->n)
		{
			_swap(&sorted, &current, &(*list));
			print_list(*list);
		}
		next = next->next;
	}
}

/**
 * _swap - swap two nodes
 * @sorted: temporal pointer to node
 * @current: temporal pointer to node
 * @list: head pointer to list
 * Return: nothing
 */
void _swap(listint_t **sorted, listint_t **current, listint_t **list)
{

	if ((*current)->prev == NULL)
	{
		(*current)->prev = *sorted;
		(*current)->next = (*sorted)->next;
		(*sorted)->next = *current;
		if ((*current)->next != NULL)
			(*current)->next->prev = *current;
		(*sorted)->prev = NULL;
		*list = *sorted;
		*current = (*sorted)->prev;
	}
	else
	{
		(*sorted)->prev = (*current)->prev;
		(*current)->next = (*sorted)->next;
		(*sorted)->next = *current;
		(*current)->prev = *sorted;
		if ((*current)->next != NULL)
			(*current)->next->prev = *current;
		(*sorted)->prev->next = *sorted;
		*current = (*sorted)->prev;
	}
}
