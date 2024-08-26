/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 08:20:58 by rishibas          #+#    #+#             */
/*   Updated: 2024-08-26 08:20:58 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

void	init_philo_info(t_philo	*philo, t_info *info, int num)
{
	philo->info = info;
	philo->num_of_times_eaten = 0;
	philo->id = num + 1;
	philo->last_eat_times = 0;
	philo->is_full = false;
	if (info->argc == 6)
		philo->num_of_meals = 0;
	else
		philo->num_of_meals = 1;
}

void	delete_sem(void)
{
	sem_unlink("/sem_done");
	sem_unlink("/sem_print");
	sem_unlink("/sem_stop");
	sem_unlink("/sem_fork");
	sem_unlink("/sem_dead");
	sem_unlink("/sem_philo");
	sem_unlink("/sem_shared");
	sem_unlink("/sem_see");
	sem_unlink("/sem_error");
}

bool	init_other_semaphore(t_info *info)
{
	info->sem_dead = sem_open("/sem_dead", O_CREAT, 0644, 1);
	if (info->sem_dead == SEM_FAILED)
		return (false);
	info->sem_philo = sem_open("/sem_philo", O_CREAT, 0644, 0);
	if (info->sem_philo == SEM_FAILED)
		return (false);
	info->sem_error = sem_open("/sem_error", O_CREAT, 0644, 1);
	if (info->sem_error == SEM_FAILED)
		return (false);
	info->sem_shared = sem_open("/sem_shared", O_CREAT, 0644, 1);
	if (info->sem_shared == SEM_FAILED)
		return (false);
	info->sem_see = sem_open("/sem_see", O_CREAT, 0644, 1);
	if (info->sem_see == SEM_FAILED)
		return (false);
	return (true);
}

bool	init_semaphore(t_info *info)
{
	delete_sem();
	info->sem_fork = sem_open("/sem_fork", O_CREAT, 0644, info->num_of_philo);
	if (info->sem_fork == SEM_FAILED)
		return (false);
	info->sem_done = sem_open("/sem_done", O_CREAT, 0644, 0);
	if (info->sem_done == SEM_FAILED)
		return (false);
	info->sem_print = sem_open("/sem_print", O_CREAT, 0644, 1);
	if (info->sem_print == SEM_FAILED)
		return (false);
	info->sem_stop = sem_open("/sem_stop", O_CREAT, 0644, 1);
	if (info->sem_stop == SEM_FAILED)
		return (false);
	return (init_other_semaphore(info));
}

bool	init_info(t_info *info, int argc, char **argv)
{
	int	i;

	info->argc = argc;
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->num_of_times_philo_must_eat = ft_atoi(argv[5]);
	info->stop_sim = false;
	info->is_done = false;
	i = -1;
	while (++i < info->num_of_philo)
		init_philo_info(&info->philo[i], info, i);
	return (init_semaphore(info));
}
