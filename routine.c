#include "philosophers.h"

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
