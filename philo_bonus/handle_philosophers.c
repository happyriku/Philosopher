#include "philosophers_bonus.h"

bool	is_philo_dead(t_philo *philo)
{
	if (philo->info->time_to_die <= get_time() - philo->info->start_time - philo->last_eat_times)
	{
		pthread_mutex_lock(&philo->info->shared_mutex);
		philo->info->is_done = true;
		pthread_mutex_unlock(&philo->info->shared_mutex);
		return (true);
	}
	return (false);
}

// void	waiter(t_philo	*philo)
// {
// 	if (philo->id % 2 != 0)
// 		skip_time(100);
// 	sem_post(&philo->info->waiter);
// 	exit(0);
// }

void	handle_philosophers(t_info *info)
{
	int		i;
	pid_t	pid;

    i = 0;
    while (i < info->num_of_philo)
    {
		pid = fork();
		if (pid == -1)
			print_error("failed to fork()");
        else if (pid > 0)
		{
			routine(&info->philo[i]);
			kill(pid, SIGKILL);
		}
		// else if (pid == 0)
		// 	waiter(&info->philo[i]);
        i++;
    }
}