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
	if (num == info->num_of_philo)
		philo->left_fork = 0;
	else
		philo->left_fork = num + 1;
}

void	init_mutex(t_info *info)
{
	pthread_mutex_init(info->fork, NULL);
}

void	init_info(t_info *info)
{
	int	i;

	info->start_times = 0;
	info->philo[info->num_of_philo];
	info->is_done = false;
	init_mutex(info);
	info->fork[info->num_of_philo];
	i = 0;
	while (i < info->num_of_philo)
	{
		init_player_info(&info->philo[i], info, i);
		i++;
	}
}
