#include "../include/philosophers_bonus.h"

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
		sem_wait(philo->info->sem_shared);
		if (philo->info->time_to_die <= get_time() - philo->info->start_time - philo->last_eat_times)
		{
			sem_wait(philo->info->sem_dead);
			filter_and_output_actions(philo, DIE);
			sem_post(philo->info->sem_done);
			break ;
		}
		if (philo->num_of_meals == philo->info->num_of_times_philo_must_eat && philo->is_eaten)
		{
			sem_post(philo->info->sem_philo);
			philo->is_eaten = false;
		}
		sem_post(philo->info->sem_shared);
		usleep(100);
	}
	return (NULL);
}

void    routine(t_philo	*philo)
{
	if (pthread_create(&philo->thread, NULL, individual_grim_reaper, (void	*)philo) != 0)
		print_error("pthread_create error");
	if (philo->id % 2 != 0)
		thinking(philo, true);
    while (1)
	{
		taking_fork(philo);
		eating_spaghetti(philo);
		sleeping(philo);
		thinking(philo, false);
	}
}
