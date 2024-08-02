/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:35:53 by rishibas          #+#    #+#             */
/*   Updated: 2024/08/02 10:35:53 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

# define MAX_OF_PHILO 200

// typedef struct s_player	t_player;

typedef enum e_action
{
	TAKING,
	SLEEPING,
	EATING,
	THINKING,
	DIE,
}	t_action;

typedef struct s_player
{
	int				id;
	int				right_fork;
	int				left_fork;
	t_info			*info;

}	t_player;

typedef struct s_info
{
	t_player		player_info;
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_must_eat;
	int				start_times;
	pthread_mutex_t	fork[MAX_OF_PHILO];
	t_player		philo[MAX_OF_PHILO];
	bool			is_done;

}	t_info;

int		main(int argc, char **argv);
void	print_error(char *message);
void	handle_argm_error(int argc, char **argv, t_info *info);

#endif