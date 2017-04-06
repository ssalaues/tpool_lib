#ifndef FT_CONTRAST_H
# define FT_CONTRAST_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_img
{
	int		h;
	int		w;
	unsigned char	g;
	int		**data;
}		t_img;

# endif
