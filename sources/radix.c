/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:38:46 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/01 18:59:27 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief sees how many how many times we need to bitshift right
 * to make the biggest normalised nr (which == list_len - 1!!) 0
 * @param arrlen
 * @return int
 */
int	get_max_bits(int list_len)
{
	int	max_bits;

	while ((list_len - 1) >> max_bits != 0)
		max_bits++;
	return (max_bits);
}

void	radix(t_stack **stack_a, t_stack **stack_b, int list_len)
{
	const int	max_bits = get_max_bits(list_len);
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < max_bits)
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
