#include "philosophers_bonus.h"

void    routine(t_philo	*philo)
{
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
