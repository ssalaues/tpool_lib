#include "ft_contrast.h"

t_img	contrast(t_img img)
{
	int	i;
	int j;
	int	*tmp;

	j = 0;
	while (j < 1000)
	{
		i = 1;
		tmp = img.data[j];
		while (i < tmp[0])
		{
			tmp[i] = (tmp[i] * img.c) / 100;
			if (tmp[i] > img.g)
				tmp[i] = img.g;
			ft_putnbr(tmp[i]);
			write(1, " ", 1);
			i++;
		}
		free(tmp);
		j++;
	}
//	if(img.ret == 1)
//		readin(img); 
	return (img);
}
void	*readin(t_img img)
{
	char	*line;

	img.ct = 0;
	img.data = (int**)ft_memalloc(1000 * sizeof(int*));
	while((img.ret = get_next_line(img.fd1, &line)) && img.ct <= 1000)
	{
		img.data[img.ct] = ft_atoi_array(line);
		ft_strdel(&line);
		img.ct++;
	}
//	if (img.ret == 1)
//		contrast(img);
	return(NULL);
}

void	init(t_img *img)
{
	char	*line;

	line = ft_strnew(0);
	get_next_line(img->fd1, &img->type);
	dprintf(img->fd, "%s\n", img->type);
	get_next_line(img->fd1, &line);
	dprintf(img->fd, "%s\n", line);
	img->w = ft_atoi(line);
	img->h = ft_atoi(ft_strchr(line, ' '));
	get_next_line(img->fd1, &line);
	dprintf(img->fd, "%s\n", line);
	img->g = ft_atoi(line);
	readin(*img);
}
