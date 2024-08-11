/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:31:09 by rishibas          #+#    #+#             */
/*   Updated: 2024/08/02 12:48:28 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    taking_fork(t_player *philo)
{
    pthread_mutex_lock(&philo->info->fork[philo->right_fork]);
    print_action(philo, TAKING);
    pthread_mutex_lock(&philo->info->fork[philo->left_fork]);
    print_action(philo, TAKING);
}

void    eating_spaghetti(t_player *philo)
{
    print_action(philo, EATING);
    philo->last_eat_time = get_time() - philo->info->start_times;
    skip_to_time(philo->info->time_to_eat, get_time());
    pthread_mutex_unlock(&philo->info->fork[philo->right_fork]);
    pthread_mutex_unlock(&philo->info->fork[philo->left_fork]);
}

void    sleeping(t_player *philo)
{
    print_action(philo, SLEEPING);
    skip_to_time(philo->info->time_to_sleep, get_time());
}

void    thinking(t_player *philo)
{
    print_action(philo, THINKING);
}

void    died(t_player *philo)
{
    pthread_mutex_lock(&philo->info->die);
    print_action(philo, DIE);
    philo->info->is_done = true;
    pthread_mutex_unlock(&philo->info->die);
    exit(0);
}
