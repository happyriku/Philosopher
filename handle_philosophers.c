#include "philosophers.h"

bool    check_is_died(t_player *philo)
{
    if (philo->info->time_to_die <= get_time() - philo->info->start_times - philo->last_eat_time)
    {
        classify_by_actions(philo, DIE);
        return (true);
    }
    return (false);
}

void    *monitor(t_player *philo)
{
    int i;

    i = 0;
    while (!philo->info->is_done)
    {
        if (check_is_died(&philo[i]))
            break ;
        i++;
        if (i == philo->info->num_of_philo)
            i = 0;
    }
    return (NULL);
}

void    handle_philosophers(t_info *info)
{
    int i;

    info->start_times = get_time();
    i = 0;
    while (i < info->num_of_philo)
    {
        pthread_create(&info->philo[i].thread, NULL, (void *)routine, &info->philo[i]);
        i++;
    }
    pthread_create(&info->philo->monitor_thread, NULL, (void *)monitor, info->philo);
    pthread_join(info->philo->monitor_thread, NULL);
    i = 0;
	while (i < info->num_of_philo)
	{
		pthread_join(info->philo[i].thread, NULL);
		i++;
	}
}
