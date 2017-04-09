#ifndef FT_CONTRAST_H
# define FT_CONTRAST_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <fcntl.h>

typedef struct s_img
{
	int				h;
	int				w;
	int				ct;
	int				**data;
	char			*type;
	unsigned char	g;
}				t_img;

# endif
