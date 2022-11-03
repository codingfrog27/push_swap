/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 16:19:41 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/02 18:54:23 by mde-cloe      ########   odam.nl         */
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
	if (i > 9)
	{
		if (i == 10 && str[i - 1] != '8' && str[i - 1] != '9')
			return (true);
		if (i == 11 && str[0] == '-' && str[i - 1] != '9')
			return (true);
		return (false);
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
				return (true);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (false);
}

int	*input_to_array(int arrlen, char **argv)
{
	int	*nbrs;
	int	i;

	nbrs = ft_calloc(sizeof(int), arrlen);
	if (!nbrs)
		error_exit("malloc fail");
	i = 0;
	while (i < arrlen)
	{
		if (!is_valid_input(argv[i + 1]))
			error_exit("invalid input");
		nbrs[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (contains_doubles(nbrs, arrlen))
	{
		free(nbrs);
		error_exit("contains double digits");
	}
	normalize_nbrs(nbrs, arrlen);
	return (nbrs);
}

t_stack	*init_stack_a(int *arr, int arrlen)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*head;

	i = 0;
	stack_a = new_node(arr[i]);
	head = stack_a;
	// ft_printf("node %i = %i\n", i, stack_a->nbr);
	i++;
	while (i < arrlen)
	{
		stack_a->next = new_node(arr[i]);
		stack_a->next->prev = stack_a;
		stack_a = stack_a->next;
		// ft_printf("node %i = %i\n", i, stack_a->nbr);
		i++;
	}
	stack_a->next = head;
	stack_a->next->prev = stack_a;
	return (head);
	// remove printf's
	//  and if the stack is upside down switch next and prev in the loop :)
	// (list is circular though so idk how much it matters)
}