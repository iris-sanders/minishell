# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irsander <irsander@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 13:27:31 by irsander          #+#    #+#              #
#    Updated: 2024/07/12 17:43:07 by irsander         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
LDFLAGS		= -lreadline

LIB_DIR = libft
INCL = -I ./incl -I $(LIB_DIR)/incl

FILES = main.c \
		lexer/lexer.c \

SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/, $(FILES))	

OBJ_DIR = src/obj
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

LIBFT = $(LIB_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $^ $(INCL) $(CFLAGS) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIB_DIR)

# $(OBJ_DIR):
# 	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/lexer
	$(CC) -c $< $(INCL) $(CFLAGS) -o $@ 

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean make fclean re