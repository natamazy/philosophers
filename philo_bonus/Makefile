# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 18:15:04 by natamazy          #+#    #+#              #
#    Updated: 2024/04/18 21:05:52 by natamazy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = philo_bonus

# Compilator
CC = cc
# Compilator flags
CFLAGS = -Wall -Wextra -Werror -Iincludes #-g3 -fsanitize=thread

# Headers
HEADERS = includes/philo_bonus.h

# Source directory
SRCS_DIR = sources/
# Objects directory
OBJS_DIR = objects/

# Source file names
SRCS_NAME = philo.c \
			validation.c \
			initialization.c \
			checker.c \
			time.c \
			simulation.c

# Objects file names
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
OBJS_NAME = $(SRCS_NAME:.c=.o)

# Compilation process
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -g -lpthread

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS) Makefile
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

# Remaking
re: clean all

# PHONY files
.PHONY: all clean fclean re