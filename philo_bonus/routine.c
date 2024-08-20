#include "philosophers_bonus.h"

bool	is_philo_dead(t_philo *philo)
{
	if (philo->info->time_to_die <= get_time() - philo->info->start_time - philo->last_eat_times)
	{
		filter_and_output_actions(philo, DIE);
		return (true);
	}
	return (false);
}

void    routine(t_philo	*philo)
{
	philo->info->start_time = get_time();
    while (!philo->info->is_done)
	{
		if (is_philo_dead(philo))
			break ;
		taking_fork(philo);
		eating_spaghetti(philo);
		sleeping(philo);
		thinking(philo);
	}
}
