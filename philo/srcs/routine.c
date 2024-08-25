#include "../include/philosophers.h"

void    check_must_eat_times(t_player *philo)
{
    philo->eat_count++;
    pthread_mutex_lock(&philo->info->time_mutex);
    philo->last_eat_time = get_time() - philo->info->start_times;
    pthread_mutex_unlock(&philo->info->time_mutex);
    if (philo->eat_count == philo->info->num_of_times_must_eat
            && philo->is_eaten == false)
    {
        pthread_mutex_lock(&philo->info->eaten_mutex);
        philo->info->count++;
        philo->is_eaten = true;
        pthread_mutex_unlock(&philo->info->eaten_mutex);
    }
    if (philo->info->count == philo->info->num_of_philo)
    {
        pthread_mutex_lock(&philo->info->done_mutex);
        philo->info->is_done = true;
        pthread_mutex_unlock(&philo->info->done_mutex);
    }
}

void    *routine(void *philosopher)
{
    t_player *philo;

    philo = (t_player *)philosopher;
    if (philo->id % 2 != 0)
        skip_to_time(100, philo->info);
    while (!philo->info->is_done)
    {
        taking_fork(philo);
        eating_spaghetti(philo);
        sleeping(philo);
        thinking(philo);
    }
    return (NULL);
}
