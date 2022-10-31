/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 17:48:11 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/10/31 18:23:57 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//parsing
int		*input_to_array(int arrlen, char **argv);
void	normalize_nbrs(int *nbrs, int arrlen);
int		*intarr_dup( int *src, int size);
bool	contains_doubles(int *nbrs, int arrlen);

//sorting
void	bubble_sort(int *nbrs, int arrlen);

//utils
void	error_exit(char *str);
void	print_array(int *nbrs, int arrlen);
t_stack	*new_node(int nbr);

//init list
t_stack	*arr_to_list(int *arr, int arrlen);
t_stack	*init_stack_a(int *arr, int arrlen);

//operations
void	swap(t_stack *stack, char c);
void	super_swap(t_stack *stack_a, t_stack *stack_b);
t_stack	*yoink_node(t_stack **stack);
void	push(t_stack **src, t_stack **dest, char c);
#endif