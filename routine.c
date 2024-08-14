#include "philosophers.h"

void    *routine(void *philosopher)
{
    t_player *philo;

    philo = (t_player *)philosopher;
    if (philo->id % 2 == 0)
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
