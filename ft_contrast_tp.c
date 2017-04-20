#include "ft_contrast.h"
#include "ft_tp.h"
/*
void	*thread_func(void *arg)
{
	t_job_type	*job;

	job = arg;

	printf("%s\n", (job->data));

	job->ret = 1;

	return (NULL);
}

int main(void)
{
	t_tp_thread *tp;

	tp = ft_tp_create(8);

	t_job_type	*j1 = malloc(sizeof(*j1));
	j1->data = "hey i'm job 1";
	t_job_type	*j2 = malloc(sizeof(*j2));
	j2->data = "hey i'm job 2";
	t_job_type	*j3 = malloc(sizeof(*j3));
	j3->data = "hey i'm job 3";
	t_job_type	*j4 = malloc(sizeof(*j4));
	j4->data = "hey i'm job 4";

	ft_tp_add_task(tp, &thread_func, j1);
	ft_tp_add_task(tp, &thread_func, j2);
	ft_tp_add_task(tp, &thread_func, j3);
	ft_tp_add_task(tp, &thread_func, j4);

	ft_tp_wait_for_queue(tp);

	return (0);
}
*/
void	tp_init(t_img *img)
{
	t_tp_thread *tp;

	tp = ft_tp_create(8);
	init(img);
	//ft_tp_add_task(tp, readin, img);
}

int	main(int ac, char **av)
{
	t_img	img;
	int		fd;

	img.fd = 0;
	fd = 0;
	if (ac == 4)
	{
		img.c = atoi(av[3]);
		if ((img.fd = open(av[2], O_RDWR | O_CREAT | O_APPEND | O_EXCL, 0755)) < 0)
			return(-1);
		if((img.fd1 = open(av[1], O_RDONLY)) < 0 || !ft_strstr(av[1], ".pgm"))
			return(-1);
		tp_init(&img);
		printf("%s\n%d %d\n%d\ncount:%d\nfile:%d\n", img.type, img.w, img.h, img.g, img.c, img.fd1);
		close(img.fd);
	}
	return (0);
}
