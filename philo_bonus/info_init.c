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
	sem_init(&info->waiter, 1, 0);
	sem_init(&info->fork, 1, info->num_of_philo);
	info->sem_done = sem_open("/sem_done", O_CREAT, 0644, 1);
	info->sem_print = sem_open("/sem_print", O_CREAT, 0644, 1);
}

void	info_init(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		philo_info_init(&info->philo[i], info, i);
		i++;
	}
	semaphore_init(info);
}