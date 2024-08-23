#include "philosophers_bonus.h"

void	taking_fork(t_philo *philo)
{
	int value;

	//sem_wait(philo->info->sem_waiter);
	sem_wait(philo->info->sem_fork);
	filter_and_output_actions(philo, TAKING);
	sem_wait(philo->info->sem_fork);
	filter_and_output_actions(philo, TAKING);
}

void	eating_spaghetti(t_philo *philo)
{
	filter_and_output_actions(philo, EATING);
	philo->last_eat_times = get_time() - philo->info->start_time;
	skip_time(philo->info->time_to_eat);
	sem_post(philo->info->sem_fork);
	sem_post(philo->info->sem_fork);
	//sem_post(philo->info->sem_waiter);
}

void	sleeping(t_philo *philo)
{
	filter_and_output_actions(philo, SLEEPING);
	skip_time(philo->info->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	filter_and_output_actions(philo, THINKING);
}