/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 17:48:11 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/10/20 19:03:30 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_stack
{
	t_stack	*next;
	t_stack	*prev;
	int		nbr;
}	t_stack;

//parsing
int		*input_to_array(int arrlen, char **argv);
int		*normalize(int *nbrs, int arrlen);
int		*intarr_dup( int *src, int size);
bool	contains_doubles(int *nbrs, int arrlen);

//sorting
void	bubble_sort(int *nbrs, int arrlen);

//utils
void	error_exit(void);
void	print_array(int *nbrs, int arrlen);

#endif