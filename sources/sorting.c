/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smol_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 18:59:36 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/09 17:11:08 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * @brief sorts 3 in a hardcoded way, wrote it so that
 * it always looks where the 2 is
 * (if only we could use switch statements ;-;)
 * @param stack
 */
static void	sort_3(t_stack **stack)
{
	const int	top = (*stack)->nbr;
	const int	mid = (*stack)->next->nbr;
	const int	bot = (*stack)->prev->nbr;

	if (mid > bot && mid < top)
	{
		swap('a', *stack);
		rev_rotate('a', stack);
	}
	else if (top > mid && top < bot)
		swap('a', *stack);
	else if (bot > mid && bot < top)
		rotate('a', stack);
	else if (bot > top && bot < mid)
	{
		swap('a', *stack);
		rotate('a', stack);
	}
	else if (top < mid && top > bot)
		rev_rotate('a', stack);
}

static int	find_lowest_pos(t_stack **stack_a, int len)
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

static void	push_lowest(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	babypos;

	babypos = find_lowest_pos(stack_a, len);
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

void	sort_select(t_stack **stack_a, t_stack **stack_b, int len)
{
	if (len > 55)
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
//babypos > len / 2 works out cause index is always one smaller ^^