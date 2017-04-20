#include "ft_contrast.h"

int	main(int ac, char **av)
{
	t_img	img;

	img.fd = 0;
	if (ac == 4)
	{
		img.c = atoi(av[3]);
		if ((img.fd = open(av[2], O_RDWR | O_CREAT | O_APPEND | O_EXCL, 0755)) < 0)
			return(-1);
		if((img.fd1 = open(av[1], O_RDONLY)) < 0 || !ft_strstr(av[1], ".pgm"))
			return(-1);
		init(&img);
		printf("%s\n%d %d\n%d\ncount:%d\nfile:%d\n", img.type, img.w, img.h, img.g, img.c, img.fd);
		close(img.fd);
	}
	return (0);
}
