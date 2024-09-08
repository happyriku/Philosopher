/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 06:07:55 by rishibas          #+#    #+#             */
/*   Updated: 2024-08-26 06:07:55 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

void	kill_all_philosophers(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_of_philo)
		kill(info->pids[i], SIGKILL);
}

bool	has_simulation_stop(t_info *info)
{
	bool	res;

	sem_wait(info->sem_stop);
	res = info->stop_sim;
	sem_post(info->sem_stop);
	return (res);
}

int	check_philosopher_is_dead(t_info *info, pid_t pid)
{
	int	status;

	while (pid && waitpid(pid, &status, WNOHANG) != 0)
	{
		kill_all_philosophers(info);
		return (1);
	}
	usleep(1000);
	return (0);
}

void	stop_simulation(t_info *info)
{
	int	i;

	while (!has_simulation_stop(info))
	{
		i = 0;
		while (i < info->num_of_philo)
		{
			if (check_philosopher_is_dead(info, info->pids[i]))
			{
				info->stop_sim = true;
				sem_post(info->sem_dead);
				break ;
			}
			i++;
		}
	}
}

int	main(int argc, char	**argv)
{
	t_info	info;

	if (!is_valid_input(argc, argv))
		return (EXIT_FAILURE);
	if (!init_info(&info, argc, argv))
		return (EXIT_FAILURE);
	if (info.num_of_philo == 1)
	{
		handle_a_philosopher(&info);
		return (EXIT_SUCCESS);
	}
	else
		handle_philosophers(&info);
	stop_simulation(&info);
	cleanup_info(&info);
	return (EXIT_SUCCESS);
}
