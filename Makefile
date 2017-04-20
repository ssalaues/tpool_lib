N1 = ft_contrast

N2 = ft_contrast_tp

EX = tp_example

SRCS = \
		contrast.c \
		tp_lib.c

all: $(N1) $(N2)

$(N1): lib 
	@clang -Wall -Wextra -Werror -c $(SRCS) ft_contrast_tp.c -g -I .
	clang $(SRCS:.c=.o) ft_contrast_tp.c -g -L./libft -lft -o $(N1)

$(N2): lib 
	@clang -Wall -Wextra -Werror -c $(SRCS) ft_contrast.c -g -I .
	clang $(SRCS:.c=.o) ft_contrast.c -g -L./libft -lft -o $(N2)

example: lib
	@clang -Wall -Wextra -Werror -c $(SRCS) tp_ex.c -g
	clang $(SRCS:.c=.o) tp_ex.c -g -L./libft -lft -o $(EX) -pthread

lib:
	@make -C libft

clean:
	@make clean -C libft
	@/bin/rm -f $(SRCS:.c=.o)
	@/bin/rm -f ft_contrast.o
	@/bin/rm -f ft_contrast_tp.o
	@/bin/rm -f tp_ex.o

fclean: clean
	@cd libft && make fclean
	@/bin/rm -f $(N1)
	@/bin/rm -f $(N2)
	@/bin/rm -f $(EX)

re: fclean all
