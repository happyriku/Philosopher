#include "philosophers.h"

void    check_must_eat_times(t_player *philo)
{
    static int count = 0;

    philo->eat_count++;
    philo->last_eat_time = get_time() - philo->info->start_times;
    if (philo->eat_count == philo->info->num_of_times_must_eat
            && philo->is_eaten == false)
    {
        pthread_mutex_lock(&philo->info->eaten_mutex);
        count++;
        philo->is_eaten = true;
        pthread_mutex_unlock(&philo->info->eaten_mutex);
    }
    if (count == philo->info->num_of_philo)
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
    while (!philo->info->is_done)
    {
        taking_fork(philo);
        eating_spaghetti(philo);
        sleeping(philo);
        thinking(philo);
    }
    return (NULL);
}
