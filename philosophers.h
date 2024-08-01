#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_player
{
    int     thread_id;
    int     has_fork;
    int     fork_total_num;
    pthread_mutex_t mutex;
    pthread_cond_t cond;

} t_player;

typedef struct s_info
{
    t_player    player_info;    

} t_info;

int     main(int argc, char **argv);
void    print_error(char *message);
void    handle_argm_error(char **argv);
void    game_setting(char **argv, t_player **players, t_info *info);

#endif