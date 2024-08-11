#include "philosophers.h"

void    print_action(t_player *philo, t_action action)
{
    int elapsed_time;

    elapsed_time = get_time() - philo->info->start_times;
    if (action == TAKING)
        printf("%d %d has taken a fork\n", elapsed_time, philo->id);
    else if (action == DIE)
        printf("%d %d died\n", elapsed_time, philo->id);
    else if (action == EATING)
        printf("%d %d is eating\n", elapsed_time, philo->id);
    else if (action == SLEEPING)
        printf("%d %d is sleeping\n", elapsed_time, philo->id);
    else if (action == THINKING)
        printf("%d %d is thinking\n", elapsed_time, philo->id);
    return ;
}