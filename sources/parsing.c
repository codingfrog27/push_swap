/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 16:19:41 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/10/20 16:30:37 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*input_to_array(int arrlen, char **argv)
{
	int	*nbrs;
	int	i;

	nbrs = (int *)malloc(sizeof(int) * arrlen);
	if (!nbrs)
		exit(1);
	i = 0;
	while (i < arrlen)
	{
		if (!is_valid_input(argv[j]))
			error_exit();
		nbrs[i] = ft_atoi(argv[j + 1]);
		i++;
	}
	if (contains_doubles(nbrs, arrlen))
	{
		free(nbrs);
		error_exit();
	}
	return (nbrs);
}

int	*normalize(int *nbrs, int arrlen)
{
	int	*copy;
	int	*normal_arr;
	int	i;
	int	j;

	copy = intarr_dup(nbrs, arrlen);
	bubble_sort(copy, arrlen);
	normal_arr = intarr_dup(nbrs, arrlen);
	i = 0;
	j = 0;
	while (i < arrlen)
	{
		while (j < arrlen)
		{
			if (nbrs[i] == copy[j])
				normal_arr[i] = j;
			j++;
		}
	i++;
	j = 0;
	}
	free(copy);
	return (normal_arr);
}

bool	contains_doubles(int *nbrs, int arrlen)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < arrlen)
	{
		while (j < arrlen)
		{
			if (nbrs[i] == nbrs[j])
				return (true);
			j++;
		}
		i++;
		j = 0;
	}
	return (false);
}
