# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/09 20:50:50 by Nik               #+#    #+#              #
#    Updated: 2019/08/10 14:55:03 by vinograd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=vinograd.filler

SRCS=src/*.c

INCLUDES=libft/libft.a

#FLAGS=-Werror -Wextra -Wall

all: $(NAME)

$(NAME):
	@make -C libft/ all
	gcc -o $(NAME) $(FLAGS) $(SRCS) $(INCLUDES)

clean:
	@make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all