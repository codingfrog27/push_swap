/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotating.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 15:00:08 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/01 15:09:14 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(char c, t_stack **stack)
{
	*stack = (*stack)->next;
	ft_printf("r%c\n", c);
}

void	double_rotate(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = (*stack_a)->next;
	*stack_b = (*stack_b)->next;
	ft_printf("rr\n");
}

void	rev_rotate(char c, t_stack **stack)
{
	*stack = (*stack)->prev;
	ft_printf("r%c\n", c);
}

void	double_rev_rotate(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = (*stack_a)->prev;
	*stack_b = (*stack_b)->prev;
	ft_printf("rrr\n");
}
