/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_single_philosopher.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:28:21 by rishibas          #+#    #+#             */
/*   Updated: 2024/08/02 12:34:20 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	handle_single_philosopher(t_info *info)
{
	info->start_times = get_time();
	print_action(&info->philo[0], TAKING);
	skip_to_time(info->time_to_die, info->start_times);
	died(&info->philo[0]);
}
