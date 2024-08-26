/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 06:07:30 by rishibas          #+#    #+#             */
/*   Updated: 2024-08-26 06:07:30 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

void	*famine_reaper(void	*arg)
{
	t_info	*info;

	info = (t_info *)arg;
	while (info->start_time == 0)
		usleep(100);
	sem_wait(info->sem_done);
	sem_wait(info->sem_see);
	info->is_done = true;
	sem_post(info->sem_see);
	sem_post(info->sem_philo);
	kill_all_philosophers(info);
	return (NULL);
}

void	*gluttony_reaper(void *arg)
{
	t_info	*info;
	int		i;

	info = (t_info *)arg;
	i = -1;
	while (++i < info->num_of_philo)
	{
		sem_wait(info->sem_see);
		if (info->is_done)
			return (NULL);
		sem_post(info->sem_see);
		sem_wait(info->sem_philo);
	}
	sem_post(info->sem_done);
	kill_all_philosophers(info);
	return (NULL);
}

void	handle_philosophers(t_info *info)
{
	int		i;
	pid_t	pid;

	info->start_time = get_time();
	i = -1;
	while (++i < info->num_of_philo)
	{
		pid = fork();
		if (pid == -1)
		{
			sem_wait(info->sem_error);
			kill_all_philosophers(info);
			print_error("fork failed", info);
		}
		else if (pid > 0)
			info->pids[i] = pid;
		else if (pid == 0)
			routine(&info->philo[i]);
	}
	pthread_create(&info->famine_reaper_thread, NULL,
		famine_reaper, (void *)info);
	pthread_create(&info->gluttony_reaper_thread, NULL,
		gluttony_reaper, (void *)info);
}
