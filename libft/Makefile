# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/27 11:19:09 by fkao              #+#    #+#              #
#    Updated: 2017/08/23 16:09:43 by fkao             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

INCL	= -I./includes

SFILE	= ft_atoi.c ft_itoa.c ft_itoa_base.c ft_tolower.c ft_toupper.c \
ft_absd.c ft_absl.c \
ft_intlen.c ft_intlen_base.c ft_lstlen.c ft_strlen.c ft_countstr.c \
ft_islower.c ft_isupper.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_isspace.c \
ft_bzero.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memset.c ft_memalloc.c ft_memdel.c \
ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strcmp.c \
	ft_strncmp.c ft_strcpy.c ft_strncpy.c ft_strdup.c ft_strstr.c ft_strnstr.c \
	ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
	ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	ft_strtrim.c ft_strctrim.c ft_strsplit.c ft_strrev.c \
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstend.c ft_lstiter.c \
	ft_lstmap.c ft_lstrev.c\
ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
get_next_line.c
SDIR	= ./src/

OFILE	= $(SFILE:.c=.o) $(PRINT:.c=.o)
OBJ		= $(addprefix $(ODIR), $(OFILE))
ODIR	= ./obj/

PRINT	= ft_printf.c pf_check_format.c pf_print_flags.c pf_pull_args.c \
	pf_put_retint.c pf_tools.c pf_bonus_parts.c

FLAG	= -Wall -Wextra -Werror
RM		= rm -rf

all: $(NAME)

$(ODIR)%.o: $(SDIR)%.c
	@mkdir -p $(ODIR)
	@gcc -c $< -o $@ $(FLAG) $(INCL)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@$(RM) $(ODIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
