/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 16:19:41 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/07 20:49:05 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_valid_input(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		i++;
		if (!str[i])
			return (false);
	}
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
			return (false);
		i++;
	}
	return (true);
}

void	normalize_nbrs(int *nbrs, int arrlen)
{
	int	*copy;
	int	i;
	int	j;

	copy = intarr_dup(nbrs, arrlen);
	bubble_sort(copy, arrlen);
	i = 0;
	j = 0;
	while (i < arrlen)
	{
		while (j < arrlen)
		{
			if (nbrs[i] == copy[j])
				nbrs[i] = j;
			j++;
		}
	i++;
	j = 0;
	}
	free(copy);
}

bool	contains_doubles(int *nbrs, int arrlen)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < arrlen)
	{
		while (j < arrlen)
		{
			if (nbrs[i] == nbrs[j])
				error_exit("contains dobules", nbrs);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (false);
}

int	*input_to_array(int arrlen, char **argv)
{
	int		*nbrs;
	int		i;
	long	tmp;

	nbrs = ft_calloc(sizeof(int), arrlen);
	if (!nbrs)
		error_exit("malloc fail", nbrs);
	i = 1;
	while (argv[i])
	{
		if (!is_valid_input(argv[i]))
			error_exit("invalid input", nbrs);
		tmp = ft_atoi(argv[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			error_exit("hey Int overflow", nbrs);
		nbrs[i - 1] = (int)tmp;
		i++;
	}
	normalize_nbrs(nbrs, arrlen);
	return (nbrs);
}

t_stack	*init_stack_a(int *arr, int arrlen)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*head;

	i = 1;
	stack_a = new_node(arr[0]);
	if (!stack_a)
		error_exit("malloc fail", arr);
	head = stack_a;
	// ft_printf("node %i = %i\n", i, stack_a->nbr);
	while (i < arrlen)
	{
		stack_a->next = new_node(arr[i]);
		node_check(stack_a, i, arr);
		stack_a->next->prev = stack_a;
		stack_a = stack_a->next;
		// ft_printf("node %i = %i\n", i, stack_a->nbr);
		i++;
	}
	stack_a->next = head;
	stack_a->next->prev = stack_a;
	return (head);
}

void	node_check(t_stack *list, int len, int *nbrs)
{
	t_stack	*tmp;

	if (!list->next)
	{
		while (len > 0)
		{
			tmp = list->prev;
			free(list);
			list = tmp;
			len--;
		}
		error_exit("malloc fail", nbrs);
	}
}
