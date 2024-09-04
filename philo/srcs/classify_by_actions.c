/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify_by_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 06:40:13 by rishibas          #+#    #+#             */
/*   Updated: 2024-08-26 06:40:13 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	output_action(t_player *philo, t_action action)
{
	int	elapsed_time;

	elapsed_time = get_time() - philo->info->start_times;
	if (action == TAKING)
		printf("%s%d %d has taken a fork%s\n", color(GREEN),
			elapsed_time, philo->id, color(STOP));
	else if (action == EATING)
		printf("%s%d %d is eating%s\n", color(YELLOW),
			elapsed_time, philo->id, color(STOP));
	else if (action == SLEEPING)
		printf("%s%d %d is sleeping%s\n", color(BLUE),
			elapsed_time, philo->id, color(STOP));
	else if (action == THINKING)
		printf("%s%d %d is thinking%s\n", color(BOLD),
			elapsed_time, philo->id, color(STOP));
}

void	classify_by_actions(t_player *philo, t_action action)
{
	int	elapsed_time;

	pthread_mutex_lock(&philo->info->print_mutex);
	if (action == DIE)
	{
		elapsed_time = get_time() - philo->info->start_times;
		printf("%s%d %d died\n", color(RED), elapsed_time, philo->id);
		pthread_mutex_lock(&philo->info->done_mutex);
		philo->info->is_done = true;
		pthread_mutex_unlock(&philo->info->done_mutex);
	}
	else
	{
			usleep(1000);
		if (!check_is_done(philo))
			output_action(philo, action);
	}
	pthread_mutex_unlock(&philo->info->print_mutex);
	return ;
}
