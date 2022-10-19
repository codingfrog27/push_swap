# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mde-cloe <mde-cloe@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/19 17:10:41 by mde-cloe      #+#    #+#                  #
#    Updated: 2022/10/19 21:13:06 by mde-cloe      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := push_swap


all: $(NAME)

$(NAME):
	@gcc main.c utils.c -I LIBFT LIBFT/libft.a -o $(NAME)
	./push_swap 1 5 4 1000 54673 -50 70
	@rm -rf push_swap