/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smol_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 18:59:36 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/03 19:39:28 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack)
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

void	sort_select(t_stack **stack_a, t_stack **stack_b, int len)
{
	if (len > 39)
		radix(stack_a, stack_b, len);
	else
	{
		while (len > 3)
		{
			push_lowest(stack_a, stack_b, len);
			len--;
		}
		sort_3(stack_a);
		while (*stack_b)
			push('a', stack_b, stack_a);
	}
}

int	find_baby_pos(t_stack **stack_a, int len)
{
	int	i;
	int	baby;
	int	babypos;

	i = 0;
	baby = (*stack_a)->nbr;
	babypos = 0;
	while (i < len)
	{
		if ((*stack_a)->nbr < baby)
		{
			baby = (*stack_a)->nbr;
			babypos = i;
		}
		*stack_a = (*stack_a)->next;
		i++;
	}
	return (babypos);
}

void	push_lowest(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	babypos;

	babypos = find_baby_pos(stack_a, len);
	if (babypos > (len / 2))
	{
		while (babypos < len)
		{
			rev_rotate('a', stack_a);
			babypos++;
		}
	}
	else
	{
		while (babypos > 0)
		{
			rotate('a', stack_a);
			babypos--;
		}
	}
	push('b', stack_a, stack_b);
}

//babypos > len / 2 works out cause index is always one smaller ^^