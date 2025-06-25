# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rolucas- <rolucas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 20:12:53 by rolucas-          #+#    #+#              #
#    Updated: 2025/06/25 20:14:41 by rolucas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Compilador e flags
CC = cc

CFLAGS = -Wall -Wextra -Werror -g

#Comando para remover
RM = rm -f	

# Nome da biblioteca
NAME = libftprintf.a

# Arquivos fonte
SRC = 

OBJ = $(SRC:.c=.o)

all: $(NAME)

# Regra para criar a biblioteca
$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

# Limpa os .o
clean:
	$(RM) $(OBJ)

# Limpa tudo (objeto + biblioteca)
fclean: clean
	$(RM) $(NAME)

# Recompila do zero
re: fclean all

teste: re
	@$(CC) $(NAME)
	./a.out
	@$(RM) $(OBJ)

.PHONY: all clean fclean re