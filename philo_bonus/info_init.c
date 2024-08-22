#include "philosophers_bonus.h"

void	philo_info_init(t_philo	*philo, t_info *info, int num)
{
	philo->info = info;
	philo->num_of_times_eaten = 0;
	philo->id = num + 1;
	philo->last_eat_times = 0;
}

void	semaphore_init(t_info *info)
{
	sem_unlink("/sem_done");
	sem_unlink("/sem_print");
	sem_unlink("/sem_stop");
	sem_unlink("/sem_waiter");
	sem_unlink("/sem_fork");
	sem_unlink("/sem_dead");
	info->sem_fork = sem_open("/sem_fork", O_CREAT, 0644, info->num_of_philo);
	info->sem_waiter = sem_open("/sem_waiter", O_CREAT, 0644, 0);
	info->sem_done = sem_open("/sem_done", O_CREAT, 0644, 0);
	info->sem_print = sem_open("/sem_print", O_CREAT, 0644, 1);
	info->sem_stop = sem_open("/sem_stop", O_CREAT, 0644, 1);
	info->sem_dead = sem_open("/sem_dead", O_CREAT, 0644, 1);
}

void	info_init(t_info *info)
{
	int	i;

	info->stop_sim = false;
	i = 0;
	while (i < info->num_of_philo)
	{
		philo_info_init(&info->philo[i], info, i);
		i++;
	}
	semaphore_init(info);
}