/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:32:05 by rishibas          #+#    #+#             */
/*   Updated: 2024/08/02 12:30:16 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_player_info(t_player *philo, t_info *info, int num)
{
	philo->info = info;
	philo->id = num + 1;
	philo->right_fork = num;
	if (num + 1 == info->num_of_philo)
		philo->left_fork = 0;
	else
		philo->left_fork = num + 1;
	philo->last_eat_time = 0;
	philo->eat_count = 0;
	philo->is_eaten = false;
}

void	init_mutex(t_info *info)
{
	int	i;

	pthread_mutex_init(&info->print_mutex, NULL);
	pthread_mutex_init(&info->shared_mutex, NULL);
	sem_init(&info->waiter, 0, 0);
	i = 0;
	while (i < info->num_of_philo)
	{
		sem_init(&info->fork[i], 0, 1);
		i++;
	}
}

void	init_info(t_info *info)
{
	int	i;

	info->start_times = 0;
	info->is_done = false;
	init_mutex(info);
	i = 0;
	while (i < info->num_of_philo)
	{
		init_player_info(&info->philo[i], info, i);
		i++;
	}
}
