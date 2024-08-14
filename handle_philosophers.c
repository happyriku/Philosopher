#include "philosophers.h"

bool    check_is_died(t_player *philo)
{
    //printf("---------------------------\n");
    //printf("time_to_die ; %d\n", philo->info->time_to_die);
    //printf("id : %d, elapsed time ; %d\n", philo->id, get_time() - philo->info->start_times - philo->last_eat_time);
    if (philo->info->time_to_die <= get_time() - philo->info->start_times - philo->last_eat_time)
    {
        classify_by_actions(philo, DIE);
        return (true);
    }
    return (false);
}

bool    check_must_eat_times(t_player *philo)
{
    static int count = 0;

    //pthread_mutex_lock(&philo->info->shared_mutex);
    if (philo->eat_count == philo->info->num_of_times_must_eat
            && philo->is_eaten == false)
    {
        count++;
        philo->is_eaten = true;
    }
    if (count == philo->info->num_of_philo)
    {
        philo->info->is_done = true;
        pthread_mutex_unlock(&philo->info->shared_mutex);
        return (true);
    }
    //pthread_mutex_unlock(&philo->info->shared_mutex);
    return (false);
}

void    *monitor(void *information)
{
    int     i;
    t_info  *info;

    info = (t_info  *)information;
    i = 0;
    while (!info->is_done)
    {
        if (check_is_died(&info->philo[i]))
            break ;
        if (check_must_eat_times(&info->philo[i]))
            break ;
        i++;
        if (i == info->num_of_philo)
            i = 0;
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