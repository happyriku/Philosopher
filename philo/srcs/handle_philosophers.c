/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 06:40:46 by rishibas          #+#    #+#             */
/*   Updated: 2024-08-26 06:40:46 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	handle_philosophers(t_info *info)
{
	int	i;

	info->start_times = get_time();
	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_create(&info->philo[i].thread, NULL,
			(void *)routine, &info->philo[i]);
		i++;
	}
	pthread_create(&info->philo->monitor_thread, NULL,
		(void *)monitor, info->philo);
	pthread_join(info->philo->monitor_thread, NULL);
	i = 0;
	while (i < info->num_of_philo)
	{
		printf("philo id : %d\n", info->philo->id);
		pthread_join(info->philo[i].thread, NULL);
		i++;
	}
}
