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

void	thinking(t_philo *philo, bool silent)
{
	int	time_to_think;
	int	elapsed_time;

	//printf("philo id : %d\n", philo->id);
	//printf("elapsed_time : %d\n", get_time() - philo->info->start_time);
	elapsed_time = (get_time() - philo->info->start_time - philo->last_eat_times);
	//printf("time since last meal : %d\n", elapsed_time);
	time_to_think = (philo->info->time_to_die - elapsed_time - philo->info->time_to_eat) / 2;
	//printf("time_to_think : %d\n", time_to_think);
	if (time_to_think < 0)
		time_to_think = 0;
	if (silent == false)
		filter_and_output_actions(philo, THINKING);
	skip_time(time_to_think);
}