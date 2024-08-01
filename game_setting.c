#include "philosophers.h"

void    game_setting(char **argv, t_player **players, t_info *info)
{
    int         philo_num;
    int         i;

    philo_num = atoi(argv[1]);
    info->player_info.fork_total_num = philo_num;
    (*players) = (t_player *)malloc(sizeof(t_player) * (philo_num));
    if (*players == NULL)
        print_error("failed to allocate memory!");
    i = -1;
    while (++i < philo_num)
    {
        (*players)[i].thread_id = (i + 1);
        (*players)[i].has_fork = 0;
        if (pthread_mutex_init(&(*players)[i].mutex, NULL) != 0)
        {
            free(players);
            print_error("failed to initialize mutex");
        }
        if (pthread_cond_init(&(*players)[i].cond, NULL) != 0)
        {
            pthread_mutex_destroy(&(*players)[i].mutex);
            free(players);
            print_error("failed to initialize condition variable");
        }
    }
    return ; 
}