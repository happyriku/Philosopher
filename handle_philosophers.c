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

void    *prioritizing_philo(t_player *philo)
{
    int max;
    int max_id;
    int i;

    max = 0;
    i = 0;
    while (!philo->info->is_done)
    {
        if (check_is_died(&philo[i]))
            break ;
        if (max < get_time() - philo[i].last_eat_time)
        {
            max = get_time() - philo[i].last_eat_time;
            max_id = i;
        }
        i++;
        if (i == philo->info->num_of_philo)
        {
            sem_post(&philo[max_id].info->waiter);
            i = 0;
        }
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
    pthread_create(&info->philo->prioritize_thread, NULL, (void *)prioritizing_philo, info->philo);
    pthread_join(info->philo->prioritize_thread, NULL);
    i = 0;
	while (i < info->num_of_philo)
	{
		pthread_join(info->philo[i].thread, NULL);
		i++;
	}
}
