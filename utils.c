/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 20:42:44 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/10/19 21:37:57 by mde-cloe      ########   odam.nl         */
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
		error_exit();
	while (i < size)
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
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

void	error_exit(void)
{
	ft_printf("\033[0;31mERROR\n");
	exit(0);
}

bool	is_valid_input(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
			return (false);
	}
	return (true);
}
