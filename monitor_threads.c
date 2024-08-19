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
