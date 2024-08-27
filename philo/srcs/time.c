/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:17:22 by rishibas          #+#    #+#             */
/*   Updated: 2024/08/02 11:36:38 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	get_time(void)
{
	struct timeval	tp;
	int				time;

	if (gettimeofday(&tp, NULL) != 0)
		print_error("gettimeofday function failed");
	time = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return (time);
}

void	skip_to_time(int target_time, t_info *info)
{
	int	start_time;

	start_time = get_time();
	while (target_time > get_time() - start_time)
	{
		if (!info->is_done)
			usleep(100);
	}
	return ;
}
