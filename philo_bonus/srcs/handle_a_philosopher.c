/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_a_philosopher.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 06:07:20 by rishibas          #+#    #+#             */
/*   Updated: 2024-08-26 06:07:20 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

void	handle_a_philosopher(t_info *info)
{
	info->start_time = get_time();
	filter_and_output_actions(&info->philo[0], TAKING);
	skip_time(info->time_to_die);
	filter_and_output_actions(&info->philo[0], DIE);
}
