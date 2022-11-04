/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 17:47:49 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/04 18:22:21 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			*nbrs;
	t_stack		*stack_a;
	t_stack		*stack_b;
	const int	arrlen = argc - 1;

	if (argc > 2)
	{
		nbrs = input_to_array(arrlen, argv);
		print_array(nbrs, arrlen);
		stack_a = init_stack_a(nbrs, arrlen);
		stack_b = NULL;
		free(nbrs);
		// if (!is_sorted(stack_a))
		// 	sort_select(&stack_a, &stack_b, arrlen);
		print_list(stack_a, arrlen);
		free_list(stack_a, arrlen);
	}
	return (0);
}

void	free_list(t_stack *stack, int len)
{
	t_stack	*temp;

	while (len > 0)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
		len--;
	}
}
