/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 17:48:11 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/03 18:16:03 by mde-cloe      ########   odam.nl         */
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
void	radix(t_stack **stack_a, t_stack **stack_b, int list_len);
int		get_max_bits(int list_len);

//utils
void	error_exit(char *str);
void	print_array(int *nbrs, int arrlen);
t_stack	*new_node(int nbr);
void	free_list(t_stack *stack, int len);
void	print_list(t_stack *stack, int len);

//init list
t_stack	*arr_to_list(int *arr, int arrlen);
t_stack	*init_stack_a(int *arr, int arrlen);

//operations
void	swap(char c, t_stack *stack);
void	double_swap(t_stack *stack_a, t_stack *stack_b);
t_stack	*yoink_node(t_stack **stack);
void	push(char c, t_stack **src, t_stack **dest);

void	rotate(char c, t_stack **stack);
void	rev_rotate(char c, t_stack **stack);
void	double_rotate(t_stack **stack_a, t_stack **stack_b);
void	double_rev_rotate(t_stack **stack_a, t_stack **stack_b);

void	sort_3(t_stack **stack);
bool	is_sorted(t_stack *stack);
void	sort_select(t_stack **stack_a, t_stack **stack_b, int arrlen);
void	push_lowest(t_stack **stack_a, t_stack **stack_b, int len);
int		find_baby_pos(t_stack **stack_a, int len);
#endif