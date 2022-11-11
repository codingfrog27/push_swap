/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 20:42:44 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/09 17:06:37 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_array(int *nbrs, int arrlen)
{
	int	i;

	i = 0;
	while (i < arrlen)
	{
		ft_printf("index %i = %i\n", i, nbrs[i]);
		i++;
	}
}

void	error_exit(int	*nbr)
{
	free(nbr);
	write(2, "Error\n", 7);
	exit(0);
}

void	print_list(t_stack *stack, int len)
{
	while (len > 0)
	{
		ft_printf("%d\n", stack->nbr);
		stack = stack->next;
		len--;
	}
}

bool	is_sorted(t_stack *stack)
{
	const t_stack	*head = stack;

	while (stack->next != head)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	free_list(t_stack *stack, int len)
{
	t_stack	*temp;

	while (len > 0)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
		len--;
	}
}