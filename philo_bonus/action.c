#include "philosophers_bonus.h"

void	take_fork(t_philo *philo)
{
	int	time;

	printf("------\n");
	sem_wait(&philo->info->fork);
	printf("=====\n");
	output_actions(philo, TAKING);
	if (sem_wait(&philo->info->fork) == -1)
		return ;
	output_actions(philo, TAKING);
}