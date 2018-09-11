# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnxele <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/04 14:35:02 by vnxele            #+#    #+#              #
#    Updated: 2018/09/11 06:10:56 by vnxele           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

NAME2 = checker

SRC1 = push_swap.c operations.c operations2.c execute.c extra_ft.c hlf_cmp.c

SRC2 = checker.c operations.c operations2.c execute.c extra_ft.c

ifdef ALLOCWRAP
        LDFLAGS += $(HOME)/lib/alloc_wrap.c -ldl
endif

OBJ1            = $(addprefix $(OBJDIR),$(SRC1:.c=.o))

OBJ2            = $(addprefix $(OBJDIR),$(SRC2:.c=.o))

CC              = gcc

CFLAGS  = -Wall -Wextra -Werror -O3 -funroll-loops -march=native

LIBFT   = ./libft/libft.a
LIBINC  = -I./libft
LIBLINK = -L./libft -lft

SRCDIR  = ./src/
INCDIR  = ./includes/
OBJDIR  = ./obj/

all: obj libft $(NAME1) $(NAME2)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME2): $(OBJ2)
	$(CC) $(LDFLAGS) -o $(NAME2) $(OBJ2) $(LIBLINK)

$(NAME1): $(OBJ1)
	$(CC) $(LDFLAGS) -o $(NAME1) $(OBJ1) $(LIBLINK)


clean:
	rm -rf $(OBJDIR)
	make -C ./libft clean

fclean: clean
	rm -rf $(NAME1)
	rm -rf $(NAME2)
	make -C ./libft fclean

re: fclean all
