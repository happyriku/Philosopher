/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 06:07:09 by rishibas          #+#    #+#             */
/*   Updated: 2024-08-26 06:07:09 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

void	cleanup_sem(t_info *info)
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
}

void	cleanup_info(t_info *info)
{
	int	i;

	pthread_join(info->famine_reaper_thread, NULL);
	pthread_join(info->gluttony_reaper_thread, NULL);
	i = -1;
	while (++i < info->num_of_philo)
		pthread_join(info->philo[i].thread, NULL);
	cleanup_sem(info);
}
