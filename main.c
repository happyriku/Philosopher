#include "philosophers.h"

// void    *thread_function(void   *arg)
// {
//     t_player *player;

//     player = (t_player *)arg;
//     while (1)
//     {
//         printf("------------\n");
//         pthread_mutex_lock(&player->mutex);
//         while (player->fork_total_num <= 0)
//         {
//             pthread_mutex_unlock(&player->mutex);
//             sleep(1);
//             pthread_mutex_lock(&player->mutex);
//         }
//         player->has_fork += 1;
//         player->fork_total_num -= 1;
//         printf("Player %d has fork: %d\n", player->thread_id, player->has_fork);
//         pthread_mutex_unlock(&player->mutex);
//         sleep(2);
//         pthread_mutex_lock(&player->mutex);
//         player->has_fork -= 1;
//         player->fork_total_num += 1;
//         pthread_mutex_unlock(&player->mutex);
//         printf("Thread %d is done\n", player->thread_id);
//         return (NULL);
//     }
// }

int	main(int argc, char **argv)
{
	pthread_t	*threads;
	t_player	*players;
	int			i;
	t_info		info;
	int			num_threads;

	if (!(argc == 5 || argc == 6))
		print_error("The number of arguments is different !");
	handle_argm_error(argc, argv, &info);
	init_info(&info);
	if (info.num_of_philo == 1)
		handle_a_philosopher(&info);
	else
		handle_philosophers(&info);
	i = 0;
	while (i < info.num_of_philo)
	{
		if (sem_destroy(&info.fork[i]) != 0)
			print_error("sem_destroy error\n");
		i++;
	}
	sem_destroy(&info.waiter);
	pthread_mutex_destroy(&info.print_mutex);
	pthread_mutex_destroy(&info.eaten_mutex);
	pthread_mutex_destroy(&info.done_mutex);
    return (0);
}
