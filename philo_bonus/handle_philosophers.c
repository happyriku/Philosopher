#include "philosophers_bonus.h"

void	waiter(t_philo	*philo)
{
	if (philo->id % 2 != 0)
		skip_time(100, philo->info);
	sem_post(&philo->info->waiter);
}

// void	grim_reaper(t_info *info)
// {
// 	int	i;

// 	i = 0;
// 	while (info->start_time == 0)
// 		usleep(100);
// 	while (!info->is_done)
// 	{
// 		if (is_philo_dead(&info->philo[i]))
// 			break ;
// 		if (i == info->num_of_philo)
// 			i = 0;
// 		i++;
// 	}
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
			info->pids[i] = pid;
		else if (pid == 0)
		{
			waiter(&info->philo[i]);
			routine(&info->philo[i]);
			kill(info->pids[i], SIGKILL);
		}
        i++;
    }
	//grim_reaper(info);
}