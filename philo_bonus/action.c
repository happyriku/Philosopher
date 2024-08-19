#include "philosophers_bonus.h"

void	take_fork(t_philo *philo)
{

	sem_wait(&philo->info->fork);
	output_actions(philo, TAKING);
	if (sem_wait(&philo->info->fork) == -1)
		return ;
	output_actions(philo, TAKING);
}

void	eat_spaghetti(t_philo *philo)
{
	output_actions(philo, EATING);
	skip_time(philo->info->time_to_eat);
	sem_post(&philo->info->fork);
	sem_post(&philo->info->fork);
}

void	sleeping(t_philo *philo)
{
	output_actions(philo, SLEEPING);
	skip_time(philo->info->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	output_actions(philo, THINKING);
}