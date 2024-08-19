#include "philosophers_bonus.h"

bool	is_philo_dead(t_philo *philo)
{
	if (philo->info->time_to_die <= get_time() - philo->info->start_time - philo->last_eat_times)
		return (true);
	return (false);
}

void	handle_philosophers(t_info *info)
{
	int		i;
	pid_t	pid;

	printf("num of philo : %d\n", info->num_of_philo);
    i = 0;
    while (i < info->num_of_philo)
    {
		pid = fork();
		if (pid == -1)
			print_error("failed to fork()");
        else if (pid == 0)
		{
			routine(&info->philo[i]);
			exit(0);
		}
        i++;
    }
}