/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 17:47:49 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/09 21:19:09 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			*nbrs;
	t_stack		*stack_a;
	t_stack		*stack_b;
	const int	arrlen = argc - 1;

	if (argc > 1)
	{
		nbrs = intit_array(arrlen, argv);
		stack_a = init_list(nbrs, arrlen);
		stack_b = NULL;
		free(nbrs);
		if (!is_sorted(stack_a))
			sort_select(&stack_a, &stack_b, arrlen);
		free_list(stack_a, arrlen);
	}
	return (0);
}