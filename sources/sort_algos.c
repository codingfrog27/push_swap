/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:38:46 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/09 17:10:26 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief sees how many how many times we need to bitshift right
 * to make the biggest normalised nr (which == list_len - 1!!) 0
 * @param arrlen
 * @return int
 */
void	radix(t_stack **stack_a, t_stack **stack_b, int list_len)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (!is_sorted(*stack_a))
	{
		while (j < list_len)
		{
			if ((((*stack_a)->nbr >> i) & 1) == 1)
				rotate('a', stack_a);
			else
				push('b', stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			push('a', stack_b, stack_a);
		j = 0;
		i++;
	}
}

void	bubble_sort(int *nbrs, int arrlen)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < arrlen)
	{
		while (j + 1 < arrlen - i)
		{
			if (nbrs[j] > nbrs[j + 1])
			{
				temp = nbrs[j];
				nbrs[j] = nbrs[j + 1];
				nbrs[j + 1] = temp;
			}
			j++;
		}
		i++;
		j = 0;
	}
}
