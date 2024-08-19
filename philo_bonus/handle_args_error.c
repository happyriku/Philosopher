#include "philosophers_bonus.h"

void	handle_args_error(int argc, char **argv, t_info *info)
{
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->num_of_times_must_eat = ft_atoi(argv[5]);
	if (info->num_of_philo < 1 || info->num_of_philo > MAX_OF_PHILO)
		print_error("please make sure argv[1] (0 < num_of_philo < 201)");
	if (info->time_to_die < 1)
		print_error("please make sure argv[2] (0 < time_to_die)");
	if (info->time_to_eat < 1)
		print_error("please make sure argv[3] (0 < time_to_eat)");
	if (info->time_to_sleep < 1)
		print_error("please make sure argv[4] (0 < time_to_sleep)");
	if (argc == 6 && info->num_of_times_must_eat < 0)
		print_error("please make sure argv[5] (0 < num_of_times_must_eat)");
}