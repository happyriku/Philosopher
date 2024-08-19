#include "philosophers_bonus.h"

void	philo_info_init(t_philo	*philo, t_info *info, int num)
{
	philo->info = info;
	philo->num_of_times_eaten = 0;
	philo->id = num + 1;
}

void	semaphore_init(t_info *info)
{
	//sem_init(info->waiter, 1, (info->num_of_philo / 2));
	sem_init(&info->fork, 1, info->num_of_philo);
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