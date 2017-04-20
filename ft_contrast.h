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
	int				c;
	int				fd;
	int				fd1;
	int				ct;
	int				ret;
	int				**data;
	char			*type;
	char			*new_f;
	unsigned char	g;
}				t_img;

t_img	contrast(t_img img);
void	*readin(t_img img);
void	init(t_img *img);

# endif
