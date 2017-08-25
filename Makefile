NAME	= ft_ls

INCL	= -I./libft/includes \
			-I ft_ls.h

SFILE	= ft_ls.c \
			ft_ls_args.c \
			ft_ls_build.c \
			ft_ls_sort.c \
			ft_ls_print.c

SRC		= $(addprefix $(SDIR), $(SFILE))
SDIR	= ./

LFILE	= ./libft/libft.a
LIB		= -L./libft -lft
LDIR	= ./libft/

OFILE	= $(SRC:.c=.o)
OBJ		= $(addprefix $(ODIR), $(OFILE))
ODIR	= ./obj/

CC		= gcc
FLAG	= -Wall -Wextra -Werror
RM		= rm -rf
MC		= make -C

all: $(LFILE) $(NAME)

$(LFILE):
	@$(MC) $(LDIR) re

$(ODIR)%.o: %.c
	@mkdir -p $(ODIR)
	@$(CC) -c $(FLAG) $(INCL) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	@$(MC) $(LDIR) clean
	@$(RM) $(ODIR)

fclean: clean
	@$(RM) $(LFILE)
	@$(RM) $(NAME)

re: fclean all
