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
    sem_wait(&philo->info->waiter);
    if (philo->id % 2 == 0)
    {
        sem_wait(&philo->info->fork[philo->left_fork]);
        classify_by_actions(philo, TAKING);
        if (sem_wait(&philo->info->fork[philo->right_fork]) != 0)
        {
            sem_post(&philo->info->fork[philo->left_fork]);
            return ;
        }
        classify_by_actions(philo, TAKING);
    }
    else
    {
        sem_wait(&philo->info->fork[philo->right_fork]);
        classify_by_actions(philo, TAKING);
        if (sem_wait(&philo->info->fork[philo->left_fork]) != 0)
        {
            sem_post(&philo->info->fork[philo->right_fork]);
            return ;
        }
        classify_by_actions(philo, TAKING);
    }
}

void    eating_spaghetti(t_player *philo)
{
    classify_by_actions(philo, EATING);
    philo->eat_count++;
    philo->last_eat_time = get_time() - philo->info->start_times;
    skip_to_time(philo->info->time_to_eat, philo->info);
    sem_post(&philo->info->fork[philo->right_fork]);
    sem_post(&philo->info->fork[philo->left_fork]);
    sem_post(&philo->info->waiter);
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
