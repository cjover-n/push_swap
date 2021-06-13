# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 22:56:39 by cjover-n          #+#    #+#              #
#    Updated: 2021/06/13 20:25:45 by cjover-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	push_swap.c

SRCLIB =	ft_isalpha.c	ft_isprint.c	ft_strlcpy.c	ft_strrchr.c	\
			ft_atoi.c		ft_isascii.c	ft_strchr.c		ft_strlen.c		\
			ft_tolower.c	ft_isalnum.c	ft_isdigit.c	ft_strlcat.c	\
			ft_strncmp.c	ft_toupper.c	ft_memset.c		ft_bzero.c		\
			ft_memcpy.c		ft_memccpy.c	ft_memmove.c	ft_memchr.c		\
			ft_memcmp.c		ft_strnstr.c	ft_calloc.c		ft_strdup.c		\
			ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_putchar_fd.c	\
			ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	ft_strmapi.c	\
			ft_itoa.c		ft_split.c		ft_lstiter.c	ft_strcdup.c	\
			ft_strnew.c		ft_putchar.c	ft_putnbr.c		ft_putstr.c		\
			get_next_line.c	ft_numlen.c		ft_isspace.c	\
			ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	\
			ft_lstadd_back.c	ft_lstdelone.c	ft_lstclear.c ft_lstmap.c

DIRLIBFTSRC = Libft/

ADDLIBFT = $(addprefix $(DIRLIBFTSRC),$(SRCLIB))
SRCOBJ = $(SRC:.c=.o) $(ADDLIBFT:.c=.o)

FLAGS = -Wextra -Wall -Werror -I -g

all: $(NAME)

$(NAME): $(SRC) $(SRCOBJ) Libft/libft.h
	@gcc $(FLAGS) ./$(SRC) $(ADDLIBFT) -o push_swap

clean:
	@rm -f *.o
	@rm -f $(DIRLIBFTSRC)*.o
	@rm -f *.out
	@rm -f -r *.dSYM

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re