/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 06:08:03 by rishibas          #+#    #+#             */
/*   Updated: 2024-08-26 06:08:03 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

void	output_actions(t_philo *philo, t_action action)
{
	int	elapsed_time;

	elapsed_time = get_time() - philo->info->start_time;
	if (action == TAKING)
		printf("%s%d %d has taken a fork%s\n",
			color(GREEN), elapsed_time, philo->id, color(STOP));
	else if (action == EATING)
		printf("%s%d %d is eating%s\n",
			color(YELLOW), elapsed_time, philo->id, color(STOP));
	else if (action == SLEEPING)
		printf("%s%d %d is sleeping%s\n",
			color(BLUE), elapsed_time, philo->id, color(BLUE));
	else if (action == THINKING)
		printf("%s%d %d is thinking%s\n",
			color(BOLD), elapsed_time, philo->id, color(STOP));
}

void	filter_and_output_actions(t_philo *philo, t_action action)
{
	int	elapsed_time;

	sem_wait(philo->info->sem_print);
	if (action == DIE)
	{
		elapsed_time = get_time() - philo->info->start_time;
		printf("%s%d %d died%s\n",
			color(RED), elapsed_time, philo->id, color(STOP));
	}
	else
		output_actions(philo, action);
	sem_post(philo->info->sem_print);
}
