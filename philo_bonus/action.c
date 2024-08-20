#include "philosophers_bonus.h"

void	taking_fork(t_philo *philo)
{
	sem_wait(&philo->info->waiter);
	sem_wait(&philo->info->fork);
	filter_and_output_actions(philo, TAKING);
	if (sem_wait(&philo->info->fork) == -1)
		return ;
	filter_and_output_actions(philo, TAKING);
}

void	eating_spaghetti(t_philo *philo)
{
	filter_and_output_actions(philo, EATING);
	philo->last_eat_times = get_time() - philo->info->start_time;
	skip_time(philo->info->time_to_eat, philo->info);
	sem_post(&philo->info->fork);
	sem_post(&philo->info->fork);
	sem_post(&philo->info->waiter);
}

void	sleeping(t_philo *philo)
{
	filter_and_output_actions(philo, SLEEPING);
	skip_time(philo->info->time_to_sleep, philo->info);
}

void	thinking(t_philo *philo)
{
	filter_and_output_actions(philo, THINKING);
}