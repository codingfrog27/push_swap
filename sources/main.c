/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 17:47:49 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/01 18:11:28 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			*nbrs;
	t_stack		*stack_a;
	t_stack		*stack_b;
	const int	arrlen = argc - 1;

	if (argc < 3)
	{
		if (argc < 2)
			ft_printf("ERROR\n");
		return (0);
	}
	nbrs = input_to_array(arrlen, argv);
	stack_a = init_stack_a(nbrs, arrlen);
	stack_b = NULL;
	print_array(nbrs, arrlen);
	free(nbrs);
	radix(&stack_a, &stack_b, arrlen);
	print_list(stack_a, arrlen);
	free_list(stack_a, arrlen);
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

void	print_list(t_stack *stack, int len)
{
	while (len > 0)
	{
		ft_printf("%d\n", stack->nbr);
		stack = stack->next;
		len--;
	}
}
