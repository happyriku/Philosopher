#include "../include/philosophers_bonus.h"

void	taking_fork(t_philo *philo)
{
	sem_wait(philo->info->sem_fork);
	filter_and_output_actions(philo, TAKING);
	sem_wait(philo->info->sem_fork);
	filter_and_output_actions(philo, TAKING);
}

void	eating_spaghetti(t_philo *philo)
{
	filter_and_output_actions(philo, EATING);
	sem_wait(philo->info->sem_shared);
	philo->last_eat_times = get_time() - philo->info->start_time;
	philo->num_of_meals++;
	sem_post(philo->info->sem_shared);
	skip_time(philo->info->time_to_eat);
	sem_post(philo->info->sem_fork);
	sem_post(philo->info->sem_fork);
}

void	sleeping(t_philo *philo)
{
	filter_and_output_actions(philo, SLEEPING);
	skip_time(philo->info->time_to_sleep);
}

void	thinking(t_philo *philo, bool silent)
{
	int	time_to_think;
	int	elapsed_time;

	elapsed_time = (get_time() - philo->info->start_time - philo->last_eat_times);
	time_to_think = (philo->info->time_to_die - elapsed_time - philo->info->time_to_eat) / 2;
	if (time_to_think < 0)
		time_to_think = 0;
	if (silent == false)
		filter_and_output_actions(philo, THINKING);
	skip_time(time_to_think);
}