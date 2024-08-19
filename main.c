#include "philosophers.h"

int	main(int argc, char **argv)
{
	pthread_t	*threads;
	t_player	*players;
	int			i;
	t_info		info;
	int			num_threads;

	if (!(argc == 5 || argc == 6))
		print_error("The number of arguments is different !");
	handle_argm_error(argc, argv, &info);
	init_info(&info);
	if (info.num_of_philo == 1)
		handle_a_philosopher(&info);
	else
		handle_philosophers(&info);
	i = 0;
	while (i < info.num_of_philo)
	{
		if (pthread_mutex_destroy(&info.fork[i]) != 0)
			print_error("pthread_mutex error\n");
		i++;
	}
	pthread_mutex_destroy(&info.print_mutex);
	pthread_mutex_destroy(&info.eaten_mutex);
	pthread_mutex_destroy(&info.done_mutex);
    return (0);
}
