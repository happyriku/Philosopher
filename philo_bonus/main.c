#include "philosophers_bonus.h"

void	cleanup_semaphore(t_info *info)
{
	sem_close(info->sem_done);
	sem_close(info->sem_print);
	sem_unlink("/sem_done");
	sem_unlink("/sem_print");
}

int	main(int argc, char	**argv)
{
	t_info	info;
	int		i;

	if (!(argc == 5 || argc == 6))
		print_error("The arguments are different");
	handle_args_error(argc, argv, &info);
	info_init(&info);
	info.start_time = get_time();
	if (info.num_of_philo == 1)
		handle_a_philosopher(&info);
	else
		handle_philosophers(&info);
	cleanup_semaphore(&info);
	return (0);
}