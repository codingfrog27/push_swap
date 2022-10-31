# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mde-cloe <mde-cloe@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/19 17:10:41 by mde-cloe      #+#    #+#                  #
#    Updated: 2022/10/31 18:24:58 by mde-cloe      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

SOURCEFILES := main.c \
			init_list.c \
			operations.c \
			parsing.c \
			radix.c \
			utils.c \

SOURCES := $(addprefix sources/, $(SOURCEFILES))

all: $(NAME)

run: $(NAME)
	./push_swap 1 5 4 1000 54673 -50 70
	@rm -rf $(NAME)

clean:
	@rm -rf $(NAME)
$(NAME):
	gcc -g $(SOURCES) -I ./include -I LIBFT LIBFT/libft.a -o $(NAME)
