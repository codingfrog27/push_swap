/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smol_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 18:59:36 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/03 17:36:57 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	smol_sort(t_stack **stack, int len)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i < len)
// 	{
// 		while (j + 1 < len - i)
// 		{
// 			if ((*stack)->nbr > (*stack)->next->nbr)
// 				rev_rotate('a', stack);
// 		}
// 	}
// }

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
	//after all the small sorts are written,
	//  make a lil function ptr array? that we can index directly into :)
	if (len > 3)
		radix(stack_a, stack_b, len);
	else
		sort_3(stack_a);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b, int len)
{
	push_lowest(stack_a, stack_b, len);
	sort_3(stack_a);
	push('a', stack_b, stack_a);
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
		if ((*stack_a)->nbr > baby)
		{
			baby = (*stack_a)->nbr;
			babypos = i;
		}
		*stack_a = (*stack_a)->next;
		i++;
	}
	return (babypos);
//am I ever gonna use this multiple times in the same stack? cause if not
//I could make it a lot simpler by checking while baby != 0 instead, since
// that will always be the lowest
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
