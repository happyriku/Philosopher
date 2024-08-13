#include "philosophers.h"

bool    check_is_died(t_player *philo)
{
    // printf("---------------------------\n");
    // printf("time_to_die ; %d\n", philo->info->time_to_die);
    // printf("id : %d, elapsed time ; %d\n", philo->id, get_time() - philo->info->start_times - philo->last_eat_time);
    if (philo->info->time_to_die <= get_time() - philo->info->start_times - philo->last_eat_time)
    {
        print_action(philo, DIE);
        return (true);
    }
    return (false);
}

void    *routine(t_player *philo)
{
    if (philo == NULL || philo->info == NULL)
        print_error("philo or philo_info is NULL");
    while (!philo->info->is_done)
    {
        if (check_is_died(philo))
            print_action(philo, DIE);
        if (philo->id % 2 == 0)
            skip_to_time(philo->info->time_to_eat, philo->info->start_times);
        taking_fork(philo);
        eating_spaghetti(philo);
        sleeping(philo);
        thinking(philo);
    }
}

void    *monitor(t_info *info)
{
    int i;

    i = 0;
    while (1)
    {
        while (i < info->num_of_philo)
        {
            if (check_is_died(&info->philo[i]))
                break ;
            i++;
            if (i == info->num_of_philo)
            {
                i = 0;
                usleep(100);
            }
        }
        if (info->is_done)
            break ;
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
    pthread_create(&info->philo->monitor_thread, NULL, (void *)monitor, info);
    pthread_join(info->philo->monitor_thread, NULL);
    i = 0;
	while (i < info->num_of_philo)
	{
		pthread_join(info->philo[i].thread, NULL);
		i++;
	}
}