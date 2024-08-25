#include "../include/philosophers_bonus.h"

void	*famine_reaper(void	*arg)
{
	int	i;
	t_info	*info;

	info = (t_info *)arg;
	while (info->start_time == 0)
		usleep(100);
	sem_wait(info->sem_done);
	info->is_done = true;
	sem_post(info->sem_philo);
	i = -1;
	while (++i < info->num_of_philo)
		kill(info->pids[i], SIGKILL);
	return (NULL);
}

void	*gluttony_reaper(void *arg)
{
	t_info *info;
	int		i;

	info = (t_info *)arg;
	i = -1;
	while (++i < info->num_of_philo)
	{
		if (info->is_done)
			return (NULL);
		sem_wait(info->sem_philo);
	}
	sem_post(info->sem_done);
	i = -1;
	while (++i < info->num_of_philo)
		kill(info->pids[i], SIGKILL);
	return (NULL);
}

void	handle_philosophers(t_info *info)
{
	int		i;
	pid_t	pid;

    i = 0;
    while (i < info->num_of_philo)
    {
		pid = fork();
		if (pid == -1)
			print_error("failed to fork()");
        else if (pid > 0)
			info->pids[i] = pid;
		else if (pid == 0)
			routine(&info->philo[i]);
        i++;
    }
	pthread_create(&info->famine_reaper_thread, NULL, famine_reaper, (void	*)info);
	pthread_create(&info->gluttony_reaper_thread, NULL, gluttony_reaper, (void *)info);
}