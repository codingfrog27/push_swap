/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swapping.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 22:13:33 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/09 15:24:43 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char c, t_stack *stack)
{
	int	tmp;

	if (stack && stack->next != stack)
	{
		tmp = stack->nbr;
		stack->nbr = stack->next->nbr;
		stack->next->nbr = tmp;
	}
	if (c != 's')
		ft_printf("s%c\n", c);
}

void	double_swap(t_stack *stack_a, t_stack *stack_b)
{
	swap('s', stack_a);
	swap('s', stack_b);
	ft_printf("ss\n");
}

static t_stack	*yoink_node(t_stack **stack)
{
	t_stack	*popped_node;

	popped_node = *stack;
	if ((*stack)->next == *stack)
	{
		*stack = NULL;
		return (popped_node);
	}
	(*stack)->prev->next = (*stack)->next;
	(*stack)->next->prev = (*stack)->prev;
	*stack = (*stack)->next;
	return (popped_node);
}

void	push(char c, t_stack **src, t_stack **dest)
{
	t_stack	*pushed_node;

	pushed_node = yoink_node(src);
	if (!*dest)
	{
		pushed_node->next = pushed_node;
		pushed_node->prev = pushed_node;
		*dest = pushed_node;
	}
	else
	{
		pushed_node->next = *dest;
		pushed_node->prev = (*dest)->prev;
		(*dest)->prev->next = pushed_node;
		(*dest)->prev = pushed_node;
		*dest = pushed_node;
	}
	ft_printf("p%c\n", c);
}
