# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgueren <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 23:23:58 by wgueren           #+#    #+#              #
#    Updated: 2018/11/28 19:17:47 by wgueren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a


all: $(NAME)
	
	
$(NAME):
	gcc -Wall -Wextra -Werror -c *.c -I libft.h
	ar rc $(NAME) *.o
clean:
	/bin/rm -f *.o
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all		
