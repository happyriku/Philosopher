#include "philosophers.h"

void    *routine(t_player *philo)
{
    if (philo == NULL || philo->info == NULL)
        print_error("philo or philo_info is NULL");
    while (!philo->info->is_done)
    {
        if (philo->id % 2 == 0)
            skip_to_time(philo->info->time_to_eat, philo->info->start_times);
        taking_fork(philo);
        eating_spaghetti(philo);
        sleeping(philo);
        thinking(philo);
    }
}

void    handle_philosophers(t_info *info)
{
    int i;

    info->start_times = get_time();
    i = 0;
    while (info->num_of_philo)
    {
        pthread_create(&info->philo[i].thread, NULL, (void *)routine, &info->philo[i]);
        i++;
    }
}