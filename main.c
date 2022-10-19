/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 17:47:49 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/10/19 21:37:56 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*nbrs;
	int	arrlen;
	int	*normal_arr;

	if (argc < 2)
	{
		ft_printf("ERROR\n");
		return (1);
	}
	arrlen = argc - 1;
	nbrs = input_to_array(arrlen, argv);
	print_array(nbrs, arrlen);
	normal_arr = normalize(nbrs, arrlen);
	print_array(normal_arr, arrlen);
}

int	*input_to_array(int arrlen, char **argv)
{
	int	*nbrs;
	int	i;
	int	j;

	nbrs = (int *)malloc(sizeof(int) * arrlen);
	if (!nbrs)
		exit(1);
	i = 0;
	j = 1;
	while (i < arrlen)
	{
		if (!is_valid_input(argv[j]))
			error_exit();
		nbrs[i] = ft_atoi(argv[j]);
		i++;
		j++;
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
