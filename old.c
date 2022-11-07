/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   old.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 13:34:02 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/07 20:40:09 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_old(t_stack *stack_a)
{
	t_stack	*temp_next;
	t_stack	*temp_prev;

	temp_next = stack_a->next;
	temp_prev = stack_a->prev;
	stack_a->next = stack_a->next->next;
	stack_a->prev = temp_next;
	stack_a = stack_a->prev;
	stack_a->next = stack_a->prev;
	stack_a->prev = temp_prev;
	//wish i had my notebook for this
	//also have to do a check for
	// "Do nothing if there is only one or no elements."
	ft_printf("sa\n");
}

void	sort_3_old(t_stack **stack)
{
	if ((*stack)->nbr == 2)
	{
		if ((*stack)->next->nbr == 1)
		{
			swap('a', *stack);
			rev_rotate('a', stack);
		}
		else
			rotate('a', stack);
	}
	else if ((*stack)->nbr == 1)
	{
		if ((*stack)->next->nbr == 2)
			rev_rotate('a', stack);
		else
			swap('a', *stack);
	}
	else
	{
		swap('a', *stack);
		rotate('a', stack);
	}
}
