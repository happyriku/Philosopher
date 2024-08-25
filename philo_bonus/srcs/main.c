#include "../include/philosophers_bonus.h"

void	kill_all_philosophers(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_of_philo)
		kill(info->pids[i], SIGKILL);
}

void	cleanup_info(t_info *info)
{
	sem_close(info->sem_done);
	sem_close(info->sem_print);
	sem_close(info->sem_fork);
	sem_close(info->sem_stop);
	sem_close(info->sem_dead);
	sem_close(info->sem_philo);
	sem_close(info->sem_error);
	sem_close(info->sem_shared);
	sem_close(info->sem_see);
	sem_unlink("/sem_done");
	sem_unlink("/sem_print");
	sem_unlink("/sem_fork");
	sem_unlink("/sem_stop");
	sem_unlink("/sem_dead");
	sem_unlink("/sem_philo");
	sem_unlink("/sem_error");
	sem_unlink("/sem_shared");
	sem_unlink("/sem_see");
	pthread_join(info->famine_reaper_thread, NULL);
	pthread_join(info->gluttony_reaper_thread, NULL);
	int i = -1;
	while (++i < info->num_of_philo)
		pthread_join(info->philo[i].thread, NULL);
}

bool	has_simulation_stop(t_info *info)
{
	bool	res;

	sem_wait(info->sem_stop);
	res = info->stop_sim;
	sem_post(info->sem_stop);
	return (res);
}

int	check_philosopher_is_dead(t_info *info, pid_t pid)
{
	int status;

	while (pid && waitpid(pid, &status, WNOHANG) != 0)
	{
		kill_all_philosophers(info);
		return (1);
	}
	usleep(1000);
	return (0);
}

void	stop_simulation(t_info *info)
{
	int	i;

	while (!has_simulation_stop(info))
	{
		i = 0;
		while (i < info->num_of_philo)
		{
			if (check_philosopher_is_dead(info, info->pids[i]))
			{
				info->stop_sim = true;
				sem_post(info->sem_dead);
				break ;
			}
			i++;
		}
	}
}

int	main(int argc, char	**argv)
{
	t_info	info;

	if (!is_valid_input(argc, argv))
		return (EXIT_FAILURE);
	info_init(&info, argc, argv);
	if (info.num_of_philo == 1)
		handle_a_philosopher(&info);
	else
		handle_philosophers(&info);
	stop_simulation(&info);
	cleanup_info(&info);
	return (0);
}