/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 17:48:11 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/10/19 21:18:48 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include "libft.h"

int		*input_to_array(int arrlen, char **argv);
int		*normalize(int *nbrs, int arrlen);
int		*intarr_dup( int *src, int size);

void	error_exit(void);
void	bubble_sort(int *nbrs, int arrlen);
void	print_array(int *nbrs, int arrlen);

#endif