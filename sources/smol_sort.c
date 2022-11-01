/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smol_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 18:59:36 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/01 19:02:07 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smol_sort(t_stack **stack, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		while (j + 1 < len - i)
		{
			if ((*stack)->nbr > (*stack)->next->nbr)
				rev_rotate('a', stack);
		}
	}
}

// static void	sort_stack(t_list **stack_a, t_list **stack_b, int len)
// {
// 	if (len <= 5)
// 		simple_sort(stack_a, stack_b);
// 	else
// 		radix_sort(stack_a, stack_b);
// }