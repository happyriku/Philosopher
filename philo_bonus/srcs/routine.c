/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 06:08:16 by rishibas          #+#    #+#             */
/*   Updated: 2024-08-26 06:08:16 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

bool	is_philo_dead(t_philo *philo)
{
	sem_wait(philo->info->sem_done);
	if (philo->info->time_to_die <= get_time()
		- philo->info->start_time - philo->last_eat_times)
	{
		filter_and_output_actions(philo, DIE);
		sem_post(philo->info->sem_done);
		return (true);
	}
	return (false);
}

void	*individual_grim_reaper(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->info->sem_shared);
		if (philo->info->time_to_die <= get_time()
			- philo->info->start_time - philo->last_eat_times)
		{
			sem_wait(philo->info->sem_dead);
			filter_and_output_actions(philo, DIE);
			sem_post(philo->info->sem_done);
			sem_post(philo->info->sem_shared);
			break ;
		}
		if (philo->num_of_meals == philo->info->num_of_times_philo_must_eat
			&& !philo->is_full)
		{
			sem_post(philo->info->sem_philo);
			philo->is_full = true;
		}
		sem_post(philo->info->sem_shared);
		usleep(100);
	}
	return (NULL);
}

void	routine(t_philo	*philo)
{
	if (pthread_create(&philo->thread, NULL,
			individual_grim_reaper, (void *)philo) != 0)
		print_error("pthread_create error", philo->info);
	if (philo->id % 2 != 0)
		thinking(philo, true);
	while (1)
	{
		taking_fork(philo);
		eating_spaghetti(philo);
		sleeping(philo);
		thinking(philo, false);
	}
}
