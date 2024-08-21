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
	static int count = 0;

	i = 0;
	while (info->start_time == 0)
		usleep(100);
	while (1)
	{
		if (is_philo_dead(&info->philo[i]))
			break ;
		if (i == info->num_of_philo)
			i = 0;
		i++;
		// printf("%d\n", count);
		// count++;
		// if (count == 1000)
		// 	break ;
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		printf("---%d : %d\n", i, info->pids[i]);
		kill(info->pids[i], SIGKILL);
	}
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
		{
			printf("%d : %d\n", i, pid);
			info->pids[i] = pid;
		}
		else if (pid == 0)
		{
			waiter(&info->philo[i]);
			routine(&info->philo[i]);
		}
        i++;
    }
	grim_reaper(info);
}