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
	info_init(&info);
	if (info.num_of_philo == 1)
		handle_a_philosopher(&info);
	else
		handle_philosophers(&info);
	mutex_destroy(&info);
    return (0);
}
