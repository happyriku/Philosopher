#include "philosophers_bonus.h"

void	waiter(t_philo	*philo)
{
	if (philo->id % 2 != 0)
		skip_time(100);
	sem_post(&philo->info->waiter);
}

void	grim_reaper(t_info *info)
{
	int	i;

	while (info->start_time == 0)
		usleep(100);
	i = 0;
	while (1)
	{
		if (is_philo_dead(&info->philo[i]))
			break ;
		i++;
		if (i == info->num_of_philo)
			i = 0;
	}
	i = -1;
	while (++i < info->num_of_philo)
		kill(info->pids[i], SIGKILL);
}

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
			info->pids[i] = pid;
		else if (pid == 0)
		{
			waiter(&info->philo[i]);
			routine(&info->philo[i]);
		}
        i++;
    }
	grim_reaper(info);
}