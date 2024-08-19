#include "philosophers_bonus.h"

void    routine(t_philo	*philo)
{
    while (!info->is_done)
	{
		take_fork(philo);
		eat_spaghetti(philo);
		sleeping(philo);
		thinking(philo);
	}
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
			routine(info->philo[i]);
			exit(0);
		}
        i++;
    }
}