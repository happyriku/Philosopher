#include "philosophers.h"

void    check_is_died(t_player *philo)
{
    // printf("---------------------------\n");
    // printf("time_to_die ; %d\n", philo->info->time_to_die);
    // printf("id : %d, elapsed time ; %d\n", philo->id, get_time() - philo->info->start_times - philo->last_eat_time);
    if (philo->info->time_to_die < get_time() - philo->info->start_times - philo->last_eat_time)
        print_action(philo, DIE);    
}

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
        check_is_died(philo);
    }
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
    i = 0;
	while (i < info->num_of_philo)
	{
		pthread_join(info->philo[i].thread, NULL);
		i++;
	}
}