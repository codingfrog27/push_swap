/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 16:19:41 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/10/31 18:54:50 by mde-cloe      ########   odam.nl         */
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
		exit(1);
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
