#include "philosophers_bonus.h"

void	cleanup_semaphore(t_info *info)
{
	sem_close(info->sem_done);
	sem_close(info->sem_print);
	sem_close(info->sem_fork);
	sem_close(info->sem_stop);
	sem_close(info->sem_dead);
	sem_close(info->sem_philo);
	sem_unlink("/sem_done");
	sem_unlink("/sem_print");
	sem_unlink("/sem_fork");
	sem_unlink("/sem_stop");
	sem_unlink("/sem_dead");
	sem_unlink("/sem_philo");
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

int	kill_all_philosophers_if_one_died(t_info *info, pid_t pid)
{
	int	i;
	int status;
	int res;

	while (pid && waitpid(pid, &status, WNOHANG) != 0)
	{
		i = -1;
		while (++i < info->num_of_philo)
			kill(info->pids[i], SIGKILL);
		return (0);
	}
	usleep(1000);
	return (1);
}

void	stop_simulation(t_info *info)
{
	int	i;
	int	res;

	while (!has_simulation_stop(info))
	{
		i = 0;
		while (i < info->num_of_philo)
		{
			res = kill_all_philosophers_if_one_died(info, info->pids[i]);
			if (res == 0)
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
	int		i;

	if (!(argc == 5 || argc == 6))
		print_error("The arguments are different");
	handle_args_error(argc, argv, &info);
	info_init(&info);
	info.start_time = get_time();
	if (info.num_of_philo == 1)
		handle_a_philosopher(&info);
	else
		handle_philosophers(&info);
	stop_simulation(&info);
	cleanup_semaphore(&info);
	return (0);
}