#include "philosophers_bonus.h"

bool	is_philo_dead(t_philo *philo)
{
	if (philo->info->time_to_die <= get_time() - philo->info->start_time - philo->last_eat_times)
	{
		sem_wait(philo->info->sem_done);
		filter_and_output_actions(philo, DIE);
		sem_post(philo->info->sem_done);
		return (true);
	}
	return (false);
}

void    routine(t_philo	*philo)
{
	philo->info->start_time = get_time();
    while (1)
	{
		taking_fork(philo);
		eating_spaghetti(philo);
		sleeping(philo);
		thinking(philo);
	}
}
