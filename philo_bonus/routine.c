#include "philosophers_bonus.h"

bool	is_philo_dead(t_philo *philo)
{
	sem_wait(philo->info->sem_done);
	if (philo->info->time_to_die <= get_time() - philo->info->start_time - philo->last_eat_times)
	{
		filter_and_output_actions(philo, DIE);
		sem_post(philo->info->sem_done);
		return (true);
	}
	return (false);
}

void	*individual_grim_reaper(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->info->time_to_die <= get_time() - philo->info->start_time - philo->last_eat_times)
		{
			sem_wait(philo->info->sem_dead);
			filter_and_output_actions(philo, DIE);
			sem_post(philo->info->sem_done);
			// sem_post(philo->info->sem_dead);
			break ;
		}
		usleep(100);
	}
}

void    routine(t_philo	*philo)
{
	pthread_create(&philo->thread, NULL, individual_grim_reaper, (void	*)philo);
    while (1)
	{
		taking_fork(philo);
		eating_spaghetti(philo);
		sleeping(philo);
		thinking(philo);
	}
}
