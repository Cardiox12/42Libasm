# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/31 01:40:00 by bbellavi          #+#    #+#              #
#    Updated: 2020/11/26 11:19:34 by bbellavi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_NC			= \e[0m
COLOR_LIGHT_GREEN	= \e[1;32m

NAME 				= libasm.a
CC					= gcc -Wall -Werror -Wextra -static
EXTERN_LIBS			= -lcriterion
NASM				= nasm
NASM_FLAGS 			= -felf64
SRCS				= ft_read.s
SRCS				+= ft_strcmp.s
SRCS				+= ft_strcpy.s
SRCS				+= ft_strdup.s
SRCS				+= ft_strlen.s
SRCS				+= ft_write.s
OBJS				= $(SRCS:.s=.o)

.PHONY: all re clean

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(COLOR_LIGHT_GREEN)Building library ${basename $(NAME) .a} $(COLOR_NC)\n"
	@ar -rcs $@ $?

test: $(NAME)
	@touch test{1..2}
	@$(CC) -o main main.c $<
	@./main

%.o: %.s
	@printf "$(COLOR_LIGHT_GREEN)Compiling - ${<} $(COLOR_NC)\n"
	@$(NASM) $(NASM_FLAGS) -o $@ $?

clean:
	@rm -rf $(OBJS)
	@rm -f test1 test2

fclean: clean
	@rm -rf main
	@rm -rf $(NAME)

re: fclean all