/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   old.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 13:34:02 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/10/31 13:34:13 by mde-cloe      ########   odam.nl         */
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
	//also have to do a check for "Do nothing if there is only one or no elements."
	ft_printf("sa\n");
}