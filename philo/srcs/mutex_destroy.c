/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 06:41:21 by rishibas          #+#    #+#             */
/*   Updated: 2024-08-26 06:41:21 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	mutex_destroy(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		if (pthread_mutex_destroy(&info->fork[i]) != 0)
			print_error("pthread_mutex error\n");
		i++;
	}
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->eaten_mutex);
	pthread_mutex_destroy(&info->done_mutex);
	pthread_mutex_destroy(&info->time_mutex);
	pthread_mutex_destroy(&info->think_mutex);
}
