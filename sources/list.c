/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/09 16:59:25 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/09 17:06:48 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*new_node(int nbr)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = nbr;
	return (node);
}

static void	node_check(t_stack *list, int len, int *nbrs)
{
	t_stack	*tmp;

	if (!list->next)
	{
		while (len > 0)
		{
			tmp = list->prev;
			free(list);
			list = tmp;
			len--;
		}
		error_exit(nbrs);
	}
}

t_stack	*init_list(int *arr, int arrlen)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*head;

	i = 1;
	stack_a = new_node(arr[0]);
	if (!stack_a)
		error_exit(arr);
	head = stack_a;
	while (i < arrlen)
	{
		stack_a->next = new_node(arr[i]);
		node_check(stack_a, i, arr);
		stack_a->next->prev = stack_a;
		stack_a = stack_a->next;
		i++;
	}
	stack_a->next = head;
	stack_a->next->prev = stack_a;
	return (head);
}