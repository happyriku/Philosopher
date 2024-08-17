#include "philosophers.h"

bool    check_must_eat_times(t_player *philo)
{
    static int count = 0;

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
        return (true);
    }
    return (false);
}

void    *routine(void *philosopher)
{
    t_player *philo;

    philo = (t_player *)philosopher;
    while (!philo->info->is_done)
    {
        taking_fork(philo);
        eating_spaghetti(philo);
        if (check_must_eat_times(philo))
            break ;
        sleeping(philo);
        thinking(philo);
    }
    return (NULL);
}
