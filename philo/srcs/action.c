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

#include "../include/philosophers.h"

void    taking_fork(t_player *philo)
{
    pthread_mutex_lock(&philo->info->fork[philo->left_fork]);
    classify_by_actions(philo, TAKING);
    pthread_mutex_lock(&philo->info->fork[philo->right_fork]);
    classify_by_actions(philo, TAKING);
}

void    eating_spaghetti(t_player *philo)
{
    classify_by_actions(philo, EATING);
    check_must_eat_times(philo);
    skip_to_time(philo->info->time_to_eat, philo->info);
    pthread_mutex_unlock(&philo->info->fork[philo->right_fork]);
    pthread_mutex_unlock(&philo->info->fork[philo->left_fork]);
}

void    sleeping(t_player *philo)
{
    classify_by_actions(philo, SLEEPING);
    skip_to_time(philo->info->time_to_sleep, philo->info);
}

void    thinking(t_player *philo)
{
    classify_by_actions(philo, THINKING);
}
