# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eplumeco <eplumeco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/06 22:46:28 by fifiblop          #+#    #+#              #
#    Updated: 2015/12/08 16:59:43 by eplumeco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_PATH = ./src/
SRC_NAME =

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = ./include/

LIB_PATH = ./lib/
LIB_NAME = libft.a

CC = gcc
CFLAGS = -Werror -Wall -Wextra

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix -L,$(LIB_PATH))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
    $(CC) $(CFLAGS) $(LIB) $(INC) -o $(NAME) $(LIB_NAME) $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
    @mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
    $(CC) $(CFLAGS) $(LIB) $(INC) -o $@ -c $<

clean:
    rm -fv $(OBJ)
    @rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
    rm -fv $(NAME)

re: fclean all

norme:
    norminette $(SRC)
    norminette $(INC_PATH)*.h

.PHONY: all clean fclean re norme
