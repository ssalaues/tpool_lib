#include "ft_contrast.h"

t_img	readin(int fd)
{
	char	*line;
	t_img	img;

	line = ft_strnew(0);
	get_next_line(fd, &img.type);
	get_next_line(fd, &line);
	img.w = ft_atoi(line);
	img.h = ft_atoi(ft_strchr(line, ' '));
	get_next_line(fd, &line);
	img.g = ft_atoi(line);
	img.data = (int**)ft_memalloc(1000 * sizeof(int*));
	img.ct = 0;
	while(get_next_line(fd, &line) && img.ct <= 1000)
	{
		img.data[img.ct] = ft_atoi_array(line);
		ft_strdel(&line);
		img.ct++;
	}
	return(img);
}

int	main(int ac, char **av)
{
	t_img	img;
	int		fd;

	if (ac > 1)
	{
		if((fd = open(av[1], O_RDONLY)) < 0 || !ft_strstr(av[1], ".pgm"))
			return(0);
		img = readin(fd);
		printf("%s\n%d %d\n%d\n", img.type, img.w, img.h, img.g);
	}
	return (0);
}
