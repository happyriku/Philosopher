#include "philosophers.h"

void    print_action(t_player *philo, t_action action)
{
    int elapsed_time;

    elapsed_time = get_time() - philo->info->start_times;
    if (action == TAKING)
        printf("%s%d %d has taken a fork\n",color(GREEN), 
            elapsed_time, philo->id);
    else if (action == DIE)
        printf("%s%d %d died\n",color(RED),
            elapsed_time, philo->id);
    else if (action == EATING)
        printf("%s%d %d is eating\n",color(YELLOW),
            elapsed_time, philo->id);
    else if (action == SLEEPING)
        printf("%s%d %d is sleeping\n", color(BLUE),
            elapsed_time, philo->id);
    else if (action == THINKING)
        printf("%s%d %d is thinking\n",color(BOLD),
            elapsed_time, philo->id);
    return ;
}