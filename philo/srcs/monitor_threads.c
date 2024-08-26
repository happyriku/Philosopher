/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 06:41:07 by rishibas          #+#    #+#             */
/*   Updated: 2024-08-26 06:41:07 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

bool	check_is_died(t_player *philo)
{
	pthread_mutex_lock(&philo->info->time_mutex);
	if (philo->info->time_to_die <= get_time()
		- philo->info->start_times - philo->last_eat_time)
	{
		pthread_mutex_unlock(&philo->info->time_mutex);
		classify_by_actions(philo, DIE);
		return (true);
	}
	pthread_mutex_unlock(&philo->info->time_mutex);
	return (false);
}

void	*monitor(t_player *philo)
{
	int	i;

	i = 0;
	while (!philo->info->is_done)
	{
		if (check_is_died(&philo[i]))
			break ;
		i++;
		if (i == philo->info->num_of_philo)
			i = 0;
	}
	return (NULL);
}
