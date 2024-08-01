#include "philosophers.h"

void    *thread_function(void   *arg)
{
    t_player *player;

    player = (t_player *)arg;
    while (1)
    {
        printf("------------\n");
        pthread_mutex_lock(&player->mutex);
        while (player->fork_total_num <= 0)
        {
            pthread_mutex_unlock(&player->mutex);
            sleep(1);
            pthread_mutex_lock(&player->mutex);
        }
        player->has_fork += 1;
        player->fork_total_num -= 1;
        printf("Player %d has fork: %d\n", player->thread_id, player->has_fork);
        pthread_mutex_unlock(&player->mutex);
        sleep(2);
        pthread_mutex_lock(&player->mutex);
        player->has_fork -= 1;
        player->fork_total_num += 1;
        pthread_mutex_unlock(&player->mutex);
        printf("Thread %d is done\n", player->thread_id);
        return (NULL);
    }
}

int main(int argc, char **argv)
{
    pthread_t   *threads;
    t_player    *players;
    int         i;
    t_info      info;
    int         num_threads;

    if (argc != 5)
        print_error("The number of arguments is different !");
    handle_argm_error(argv);
    info = (t_info){0};
    game_setting(argv, &players, &info);
    num_threads = atoi(argv[1]);
    threads = malloc(num_threads * sizeof(pthread_t));
    if (!threads)
        print_error("threads failed to allocated memory");
    i = -1;
    while (++i < atoi(argv[1]))
    {
        if (pthread_create(&threads[i], NULL, thread_function, &(players[i].thread_id)) != 0)
        {
            fprintf(stderr, "Error creating thread\n");
            free(threads);
            return (1);
        }
    }
    i = -1;
    while (++i < num_threads)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            fprintf(stderr, "Error joining thread\n");
            free(threads);
            return (1);
        }
    }
    i = -1;
    while (++i < num_threads)
    {
        pthread_mutex_destroy(&players[i].mutex);
        pthread_cond_destroy(&players[i].cond);
    }
    free(threads);
    printf("Main thread is done\n");
    return (0);
}
