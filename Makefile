# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mde-cloe <mde-cloe@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/19 17:10:41 by mde-cloe      #+#    #+#                  #
#    Updated: 2022/11/01 17:54:36 by mde-cloe      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

SOURCEFILES := main.c \
			init_list.c \
			swapping.c \
			rotating.c \
			parsing.c \
			radix.c \
			utils.c \

SOURCES := $(addprefix sources/, $(SOURCEFILES))

all: $(NAME)

run: $(NAME)
	./push_swap 1 2
	@rm -rf $(NAME)

clean:
	@rm -rf $(NAME)
$(NAME):
	gcc -g $(SOURCES) -I ./include -I LIBFT LIBFT/libft.a -o $(NAME)
