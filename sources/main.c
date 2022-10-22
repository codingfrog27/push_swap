/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 17:47:49 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/10/20 16:25:57 by mde-cloe      ########   odam.nl         */
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

