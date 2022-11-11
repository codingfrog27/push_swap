/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 16:19:41 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/11 21:08:34 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*intarr_dup( int *src, int size)
{
	int	i;
	int	*copy;

	i = 0;
	copy = (int *)malloc(sizeof(int) * size);
	if (!copy)
		error_exit(src);
	while (i < size)
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}

static bool	is_valid_input(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (false);
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

static void	normalize_nbrs(int *nbrs, int arrlen)
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
			{
				nbrs[i] = j;
				break ;
			}
			j++;
		}
		i++;
		j = 0;
	}
	free(copy);
}

static void	contains_doubles(int *nbrs, int arrlen)
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
				error_exit(nbrs);
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	*intit_array(int arrlen, char **argv)
{
	int		*nbrs;
	int		i;
	long	tmp;

	nbrs = malloc(sizeof(int) * arrlen);
	if (!nbrs)
		error_exit(nbrs);
	i = 1;
	while (argv[i])
	{
		if (!is_valid_input(argv[i]))
			error_exit(nbrs);
		tmp = ft_atoi(argv[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
			error_exit(nbrs);
		nbrs[i - 1] = (int)tmp;
		i++;
	}
	contains_doubles(nbrs, arrlen);
	normalize_nbrs(nbrs, arrlen);
	return (nbrs);
}
