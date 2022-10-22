/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 19:00:11 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/10/20 19:18:40 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*arr_to_list(int *arr, int arrlen)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*new_node;

	i = 0;
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		error_exit();
	arrlen--;
	while (arrlen >= 0)
	{
		new_node =
		ft_lstadd_front(&stack_a, ft_lstnew())
	}

}
