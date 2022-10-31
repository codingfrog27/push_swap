/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 19:00:11 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/10/31 13:40:02 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack_a(int *arr, int arrlen)
{
	//might currently segfault if there's only 1 nbr!
	int		i;
	t_stack	*stack_a;
	t_stack	*head;

	i = 0;
	stack_a = new_node(arr[i]);
	head = stack_a;
	ft_printf("node %i = %i\n", i, stack_a->nbr);
	i++;
	while (i < arrlen)
	{
		stack_a->next = new_node(arr[i]);
		stack_a->next->prev = stack_a;
		stack_a = stack_a->next;
		ft_printf("node %i = %i\n", i, stack_a->nbr);
		i++;
	}
	stack_a->next = head;
	stack_a->next->prev = stack_a;
	return (head);
	// remove printf's
	//  and if the stack is upside down switch next and prev in the loop :)
	// (list is circular though so idk how much it matters)
}

t_stack	*new_node(int nbr)
{
	t_stack	*node;

	node = ft_calloc(1, sizeof(t_stack));
	if (!node)
		error_exit("malloc fail");
	node->nbr = nbr;
	return (node);
}
