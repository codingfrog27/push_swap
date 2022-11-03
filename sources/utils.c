/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 20:42:44 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/02 18:38:58 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*intarr_dup( int *src, int size)
{
	int	i;
	int	*copy;

	i = 0;
	copy = (int *)malloc(sizeof(int) * size);
	if (!copy)
		error_exit("malloc fail");
	while (i < size)
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}

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

void	error_exit(char *str)
{
	ft_printf("\033[0;31mERROR\n%s", str);
	exit(0);
}

t_stack	*new_node(int nbr)
{
	t_stack	*node;

	node = ft_calloc(1, sizeof(t_stack));
	if (!node)
		error_exit("malloc fail");
	node->nbr = nbr;
	return (node);
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
	const t_stack *head = stack;

	while (stack->next != head)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}